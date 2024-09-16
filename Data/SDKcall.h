//
// Created by CxhPr on 24-9-16.
//

#ifndef SDKCALL_H
#define SDKCALL_H

#include <memory>
#include <IAgoraRtcEngine.h>

class SDKcall{
public:
    static SDKcall& GetSDKInstance();
    [[nodiscard]] agora::rtc::IRtcEngine* GetEngine() const;

    SDKcall(const SDKcall&) = delete;
    SDKcall& operator=(const SDKcall&) = delete;

private:
    SDKcall();
    ~SDKcall();
    agora::rtc::IRtcEngine* _engine{};
    std::unique_ptr<agora::rtc::IRtcEngineEventHandler> _event_handler{};

};



#endif //SDKCALL_H
