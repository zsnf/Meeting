//
// Created by CxhPr on 24-9-15.
//

#ifndef SETTINGDATA_H
#define SETTINGDATA_H

enum class Theme {
    Dark,
    Light,
    System
};

class GeneralSettingData {
public:
    bool join_auto_start_microphone{};
    bool join_auto_start_camera{};
    bool join_use_pc_audio{};
    bool exit_when_close_mainwindow{};
    bool show_speaker_now{};
    bool show_meeting_time{};
    Theme theme { Theme::System };

};

class VideoSettingData {
public:
    int persons{};
};

#include <QtMultimedia/QMediaDevices>
#include <QtMultimedia/QAudioDevice>
#include <QList>
class AudioSettingData {
public:
    AudioSettingData()
    {
        _audio_output_devices = QMediaDevices::audioOutputs();
        _audio_input_devices = QMediaDevices::audioInputs();
        _default_audio_output_device = QMediaDevices::defaultAudioOutput();
        _default_audio_input_device = QMediaDevices::defaultAudioInput();
    }
    QAudioDevice _default_audio_output_device;
    QAudioDevice _default_audio_input_device;
private:
    QList<QAudioDevice> _audio_output_devices;
    QList<QAudioDevice> _audio_input_devices;
public slots:
    void set_default_audio_output_device(const QAudioDevice& device)
    {
        _default_audio_output_device = device;
    }
    void set_default_audio_input_device(const QAudioDevice& device)
    {
        _default_audio_input_device = device;
    }
};









#endif //SETTINGDATA_H
