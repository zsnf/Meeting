//
// Created by CxhPr on 24-9-16.
//

#ifndef SDKCALL_H
#define SDKCALL_H

#include <memory>
#include <IAgoraRtcEngine.h>
#include <QObject>
#include <QMessageBox>
class SDKcall final : public QObject, public agora::rtc::IRtcEngineEventHandler{
    Q_OBJECT
public:
    static SDKcall& GetSDKInstance();
    [[nodiscard]] agora::rtc::IRtcEngine* GetEngine() const;

    SDKcall(const SDKcall&) = delete;
    SDKcall& operator=(const SDKcall&) = delete;

    void onJoinChannelSuccess(const char* channel, agora::rtc::uid_t uid, int elapsed) override
    {
        emit on_join_channel_success(QString(channel),uid,elapsed);
    }
    void onUserJoined(agora::rtc::uid_t uid, int elapsed) override
    {
        //qDebug("%s %u",__FUNCTION__,uid);
        emit on_user_joined(uid, elapsed);
    }
    void onUserOffline(agora::rtc::uid_t uid, agora::rtc::USER_OFFLINE_REASON_TYPE reason) override
    {
        emit on_user_offline(uid, reason);
    }
    int joinChannel(const QString& key, const QString& channel, uint uid) const;
    BOOL LocalVideoPreview(HWND hVideoWnd, BOOL bPreviewOn, agora::media::base::RENDER_MODE_TYPE renderType = agora::media::base::RENDER_MODE_TYPE::RENDER_MODE_FIT);
    BOOL RemoteVideoRender(agora::rtc::uid_t uid, HWND hVideoWnd, agora::media::base::RENDER_MODE_TYPE renderType/* = RENDER_MODE_TYPE::RENDER_MODE_HIDDEN*/);
private:
    SDKcall();
    ~SDKcall() override;
    agora::rtc::IRtcEngine* _engine{};
    QMessageBox _msgbox;
    signals:
    void on_join_channel_success(const QString& channel, uint uid, int elapsed);
    void on_user_joined(uint uid, int elapsed);
    void on_user_offline(uint uid, int reason);
    void on_leave_channel();
};



#endif //SDKCALL_H
