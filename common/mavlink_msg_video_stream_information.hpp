// MESSAGE VIDEO_STREAM_INFORMATION support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief VIDEO_STREAM_INFORMATION message
 *
 * WIP: Information about video stream
 */
struct VIDEO_STREAM_INFORMATION : mavlink::Message {
    static constexpr msgid_t MSG_ID = 269;
    static constexpr size_t LENGTH = 246;
    static constexpr size_t MIN_LENGTH = 246;
    static constexpr uint8_t CRC_EXTRA = 58;
    static constexpr auto NAME = "VIDEO_STREAM_INFORMATION";


    uint8_t camera_id; /*<  Camera ID (1 for first, 2 for second, etc.) */
    uint8_t status; /*<  Current status of video streaming (0: not running, 1: in progress) */
    float framerate; /*< [Hz] Frames per second */
    uint16_t resolution_h; /*< [pix] Resolution horizontal in pixels */
    uint16_t resolution_v; /*< [pix] Resolution vertical in pixels */
    uint32_t bitrate; /*< [b/s] Bit rate in bits per second */
    uint16_t rotation; /*< [deg] Video image rotation clockwise */
    std::array<char, 230> uri; /*<  Video stream URI */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  camera_id: " << +camera_id << std::endl;
        ss << "  status: " << +status << std::endl;
        ss << "  framerate: " << framerate << std::endl;
        ss << "  resolution_h: " << resolution_h << std::endl;
        ss << "  resolution_v: " << resolution_v << std::endl;
        ss << "  bitrate: " << bitrate << std::endl;
        ss << "  rotation: " << rotation << std::endl;
        ss << "  uri: \"" << to_string(uri) << "\"" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << framerate;                     // offset: 0
        map << bitrate;                       // offset: 4
        map << resolution_h;                  // offset: 8
        map << resolution_v;                  // offset: 10
        map << rotation;                      // offset: 12
        map << camera_id;                     // offset: 14
        map << status;                        // offset: 15
        map << uri;                           // offset: 16
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> framerate;                     // offset: 0
        map >> bitrate;                       // offset: 4
        map >> resolution_h;                  // offset: 8
        map >> resolution_v;                  // offset: 10
        map >> rotation;                      // offset: 12
        map >> camera_id;                     // offset: 14
        map >> status;                        // offset: 15
        map >> uri;                           // offset: 16
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
