#pragma once


// QT
#include <QObject>
#include <QFileInfo>


namespace io {


class AlsFilesystem : public QObject
{
public:
  virtual ~AlsFilesystem() {}

  static bool load(const QFileInfo &file_);

  static bool save(const QFileInfo &file_);


private:
  explicit AlsFilesystem(QObject *parent = 0) : QObject(parent) {}
};


} // namespace io
