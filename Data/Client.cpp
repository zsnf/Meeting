//
// Created by CxhPr on 24-9-18.
//

#include "Client.h"

#include "SDKcall.h"

Client::Client() {
    _socket->open(QUrl(QStringLiteral("ws://localhost:1226")));

}

void Client::applyToken(const QString &roomid) const {
    QJsonObject obj{};
    obj["appid"] = appid;
    obj["appcertificate"] = appcertificate;
    obj["roomid"] = roomid;
    _socket->sendTextMessage(QJsonDocument(obj).toJson());
    qDebug() << "apply token!\n";
    SDKcall::GetSDKInstance().RoomID = roomid;
}

auto Client::GetSocket() const -> QWebSocket * {
    return _socket;
}

void Client::parse_message(const QString &message) {
    if (const auto json_doc = QJsonDocument::fromJson(message.toUtf8()); !json_doc.isObject()) {
        qWarning() << "Received JSON is not an object";
        return;
    }else {
        const auto json_obj = json_doc.object();
        SDKcall::GetSDKInstance().token = json_obj["token"].toString();
        SDKcall::GetSDKInstance().uid = json_obj["uid"].toInt();
        emit updated_token_and_uid(SDKcall::GetSDKInstance().token, SDKcall::GetSDKInstance().uid);
        qDebug() << "token:" << SDKcall::GetSDKInstance().token << "\nuid:" << SDKcall::GetSDKInstance().uid;
    }
}

