//
// Created by CxhPr on 24-9-18.
//

#ifndef CLIENT_H
#define CLIENT_H

#include <QWebSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>


inline const QString appid {"dd08af9a9d16489fb07092993ed50d0e"};
inline const QString appcertificate {"be7aa2860f40455588885814b3ae372b"};

class Client final : public QObject{
    Q_OBJECT
public:
    Client();
    void applyToken(const QString &roomid) const;
    [[nodiscard]] auto GetSocket() const -> QWebSocket*;
private:
    QWebSocket* _socket{ new QWebSocket};

    signals:
    void updated_token_and_uid(const QString& token, uint uid);

private slots:
    void parse_message(const QString &message);
};



#endif //CLIENT_H
