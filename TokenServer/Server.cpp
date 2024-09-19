//
// Created by CxhPr on 24-9-18.
//

#include "Server.h"

#include <QWebSocketServer>

using namespace agora::tools;
Server::Server() {
    _web_socket_server = new QWebSocketServer("TokenServer", QWebSocketServer::NonSecureMode);
    _web_socket_server->listen(QHostAddress::Any, 1226);
    connect(_web_socket_server, &QWebSocketServer::newConnection, this, &Server::on_new_connection);
}

Server::~Server() {
    _web_socket_server->close();
    delete _web_socket_server;
}

void Server::on_new_connection() const {
    const auto client_socket = _web_socket_server->nextPendingConnection();
    connect(client_socket,&QWebSocket::disconnected,client_socket,&QObject::deleteLater);
    connect(client_socket,&QWebSocket::textMessageReceived,this,&Server::on_text_message_received);
}

void Server::on_text_message_received(const QString &message) const {
    if (const auto json_doc = QJsonDocument::fromJson(message.toUtf8()); !json_doc.isObject()) {
        qWarning() << "Invalid JSON message received";
        return;
    }else{
        auto json_obj = json_doc.object();

        const auto app_ID = json_obj["appid"].toString();
        const auto app_CERTIFICATE = json_obj["appcertificate"].toString();
        const auto channel_name = json_obj["channelname"].toString();
        const uint32_t uid = generateUniqueID();
        constexpr uint32_t token_expiration_in_seconds = 86400;
        constexpr uint32_t privilege_expiration_in_seconds = 86400;

        const auto token = RtcTokenBuilder2::BuildTokenWithUid(
            app_ID.toStdString(),
            app_CERTIFICATE.toStdString(),
            channel_name.toStdString(),
            uid,
            UserRole::kRolePublisher,
            token_expiration_in_seconds,
            privilege_expiration_in_seconds
            );

        const QString token_str = QString::fromStdString(token);
        if (const auto client_socket = qobject_cast<QWebSocket*>(sender())) {
            client_socket->sendTextMessage(token_str);  // 发送 token
        }
    }
}
