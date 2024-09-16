//
// Created by CxhPr on 24-9-16.
//

#include "SDKcall.h"

SDKcall & SDKcall::GetSDKInstance() {
    static SDKcall instance;
    return instance;
}

agora::rtc::IRtcEngine * SDKcall::GetEngine() const {
    return _engine;
}

SDKcall::SDKcall() {
    _engine = createAgoraRtcEngine();
    agora::rtc::RtcEngineContext context;
    context.eventHandler = _event_handler.get();
    context.appId = "dd08af9a9d16489fb07092993ed50d0e";
    _engine->initialize(context);

    agora::util::AutoPtr<agora::media::IMediaEngine> mediaEngine;
    mediaEngine.queryInterface(_engine, agora::rtc::AGORA_IID_MEDIA_ENGINE);
    //todo registerVideoRenderFactory
    _engine->enableVideo();
}

SDKcall::~SDKcall() {
    agora::rtc::IRtcEngine::release(true);
}
