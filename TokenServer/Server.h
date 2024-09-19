//
// Created by CxhPr on 24-9-18.
//

#ifndef SERVER_H
#define SERVER_H

#include <QWebSocketServer>
#include <QWebSocket>

#include <QJsonObject>
#include <QJsonDocument>

#include <QDateTime>
#include <atomic>
#include <cstdint>

#include "TokenSDK/RtcTokenBuilder2.h"

inline std::atomic<uint32_t> counter(0);

inline uint32_t generateUniqueID() {
    // 获取当前时间的毫秒数，截取低 22 位
    const auto timestamp = static_cast<uint32_t>(QDateTime::currentMSecsSinceEpoch() & 0x3FFFFF);

    // 计数器的低 10 位，用于区分相同时间戳内的多个 ID
    const uint32_t count = counter++ & 0x3FF;

    // 组合时间戳和计数器，确保唯一性
    return (timestamp << 10) | count;
}

class Server final : public QObject{
    Q_OBJECT

public:
    Server();
    ~Server() override;
private:
    QWebSocketServer* _web_socket_server{};
private slots:
    void on_new_connection() const;
    void on_text_message_received(const QString &message) const;
};



#endif //SERVER_H
