
#ifndef TEXT_EDIT_EVENT_H_
#define TEXT_EDIT_EVENT_H_

#include "TextArea.h"
#include <QEvent>
#include <QString>
#include <QStringList>

class TextEditEvent : public QEvent {
public:
    static constexpr QEvent::Type eventType = static_cast<QEvent::Type>(QEvent::User + 1);

public:
    TextEditEvent(const QString &macroString, const QString &argument, TextArea::EventFlags flags) : QEvent(eventType), macroString_(macroString), argument_(argument), flags_(flags) {
    }

    TextEditEvent(const QString &macroString, TextArea::EventFlags flags) : QEvent(eventType), macroString_(macroString), flags_(flags) {
    }

public:
    QString argumentString() const {
        QStringList args;

        if(!argument_.isEmpty()) {
            // TODO(eteran): escape some characters as needed
            args << QLatin1Char('"') + argument_ + QLatin1Char('"');
        }

		if(flags_ & TextArea::AbsoluteFlag)  args << QLatin1String("\"absolute\"");
		if(flags_ & TextArea::ColumnFlag)    args << QLatin1String("\"column\"");
		if(flags_ & TextArea::CopyFlag)      args << QLatin1String("\"copy\"");
		if(flags_ & TextArea::DownFlag)      args << QLatin1String("\"down\"");
		if(flags_ & TextArea::ExtendFlag)    args << QLatin1String("\"extend\"");
		if(flags_ & TextArea::LeftFlag)      args << QLatin1String("\"left\"");
		if(flags_ & TextArea::OverlayFlag)   args << QLatin1String("\"overlay\"");
		if(flags_ & TextArea::RectFlag)      args << QLatin1String("\"rect\"");
		if(flags_ & TextArea::RightFlag)     args << QLatin1String("\"right\"");
		if(flags_ & TextArea::UpFlag)        args << QLatin1String("\"up\"");
		if(flags_ & TextArea::WrapFlag)      args << QLatin1String("\"wrap\"");
		if(flags_ & TextArea::TailFlag)      args << QLatin1String("\"tail\"");
		if(flags_ & TextArea::StutterFlag)   args << QLatin1String("\"stutter\"");
		if(flags_ & TextArea::ScrollbarFlag) args << QLatin1String("\"scrollbar\"");
		if(flags_ & TextArea::NoBellFlag)    args << QLatin1String("\"nobell\"");

        return args.join(QLatin1String(","));
    }

    QString toString() const {
        return QString(QLatin1String("%1(%2)")).arg(macroString_, argumentString());
    }

public:
    QString actionString() const {
        return macroString_;
    }

private:
    QString              macroString_;
    QString              argument_;
    TextArea::EventFlags flags_;
};

#endif
