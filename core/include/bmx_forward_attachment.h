//-------------------------------------------------------------------------------------------------
// File    : bmx_forward_attachment.h
// Author  : Eric Liang <eric@bmxlabs.com>
// Purpose : bmx message attachment define file.
// Created : 12 Nov 2018 by Eric Liang <eric@bmxlabs.com>
//-------------------------------------------------------------------------------------------------
//
//                    Copyright (C) 2018-2019   MaxIM.Top
//
// You may obtain a copy of the licence at http://www.maxim.top/LICENCE-MAXIM.md
//
//-------------------------------------------------------------------------------------------------

#ifndef bmx_forward_attachment_h
#define bmx_forward_attachment_h

#include <vector>
#include "bmx_message_attachment.h"

namespace floo {

class BMXMessage;
class EXPORT_API BMXForwardAttachment : public BMXMessageAttachment
{
public:

  class Message {
  public:
    Message(std::shared_ptr<BMXMessage> msg);
    virtual ~Message() {}

    int64_t msgId;
    int64_t fromId;
    int64_t clientTimestamp;
    int64_t serverTimestamp;
    std::string content;
    Type contentType;
    BMXMessageAttachmentPtr attachment;
    JSON extension;
  };

  /**
   * 构造函数
   **/
  BMXForwardAttachment() {}

  /**
   * 析构函数
   **/
  virtual ~BMXForwardAttachment() {}

  /**
   * 附件类型
   **/
  virtual Type type() const { return Type::Forward; }

  virtual BMXMessageAttachmentPtr clone() const;

private:
  BMXForwardAttachment(const BMXForwardAttachment&);
  BMXForwardAttachment& operator=(const BMXForwardAttachment&);
};

typedef std::shared_ptr<BMXForwardAttachment> BMXForwardAttachmentPtr;

}



#endif /* bmx_forward_attachment_h */
