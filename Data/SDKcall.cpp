//
// Created by CxhPr on 24-9-16.
//

#include "SDKcall.h"


using namespace agora::rtc;


SDKcall & SDKcall::GetSDKInstance() {
    static SDKcall instance;
    return instance;
}

agora::rtc::IRtcEngine * SDKcall::GetEngine() const {
    return _engine;
}

int SDKcall::joinChannel(const QString &key, const QString &channel, uint uid) const {
    if (channel.isEmpty()) {
        QMessageBox::warning(nullptr,("AgoraHighSound"),("channelname is empty"));
        return -1;
    }
    // Strarts local video preview
    _engine->startPreview();
    int r = _engine->joinChannel(key.toUtf8().data(), channel.toUtf8().data(), nullptr, uid);
    return r;
}

SDKcall::SDKcall() {
    _engine = createAgoraRtcEngine();
    agora::rtc::RtcEngineContext context;
    context.eventHandler = this;
    context.appId = "dd08af9a9d16489fb07092993ed50d0e";
    if(_engine->initialize(context) < 0) {
        QMessageBox::warning(nullptr, "sdkcall warning","initialize failed", QMessageBox::Ok);
    };


    agora::util::AutoPtr<agora::media::IMediaEngine> mediaEngine;
    mediaEngine.queryInterface(_engine, agora::rtc::AGORA_IID_MEDIA_ENGINE);
    //todo registerVideoRenderFactory
    _engine->enableVideo();
    _engine->enableAudio();
    _engine->setChannelProfile(agora::CHANNEL_PROFILE_COMMUNICATION);
}

SDKcall::~SDKcall() {
    agora::rtc::IRtcEngine::release(true);
}


BOOL SDKcall::LocalVideoPreview(HWND hVideoWnd, BOOL bPreviewOn, agora::media::base::RENDER_MODE_TYPE renderType/* = RENDER_MODE_TYPE::RENDER_MODE_FIT*/)
{
    int nRet = 0;

    if (bPreviewOn) {
        VideoCanvas vc;

        vc.uid = 0;
        vc.view = hVideoWnd;
        vc.renderMode = renderType;

        _engine->setupLocalVideo(vc);
        nRet = _engine->startPreview();
    }
    else
        nRet = _engine->stopPreview();

    return nRet == 0 ? TRUE : FALSE;
}

// Plays the remote video
BOOL SDKcall::RemoteVideoRender(uid_t uid, HWND hVideoWnd, agora::media::base::RENDER_MODE_TYPE renderType/* = RENDER_MODE_TYPE::RENDER_MODE_HIDDEN*/)
{
    int nRet = 0;

    VideoCanvas vc;

    vc.uid = uid;
    vc.view = hVideoWnd;
    vc.renderMode = renderType;

    _engine->setupRemoteVideo(vc);

    return nRet == 0 ? TRUE : FALSE;
}