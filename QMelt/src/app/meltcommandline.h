#pragma once


// QT
#include <QObject>
#include <QString>

namespace app
{


class MeltCommandLine : public QObject
{
  Q_OBJECT
public:
  static MeltCommandLine parse();

  QString basePath;
  QString localPath;
  QString remotePath;
  QString mergePath;

  bool isError;
  bool isMerging;

protected:
  /*!
   * \brief Protected constructor
   * \param parent
   */
  explicit MeltCommandLine(QObject *parent = 0) : QObject(parent) {}

  /*!
   * \brief MeltCommandLine copy constructor
   */
  MeltCommandLine(const MeltCommandLine & src_)
    : basePath(src_.basePath)
    , remotePath(src_.remotePath)
    , localPath(src_.localPath)
    , mergePath(src_.mergePath)
    , isError(src_.isError)
    , isMerging(src_.isMerging) {}
};


} // namespace app
