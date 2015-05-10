#pragma once
#include "common.h"

// APP
#include "src/app/meltcommandline.h"

// QT
#include <QObject>


M_NAMESPACE_APP_BEGIN


class Melt : public QObject
{
  Q_OBJECT
public:
  explicit Melt(const MeltCommandLine& arguments, QObject *parent = 0);


  bool loadArguments();


  QSharedPointer<ableton::AlsAbleton>& getBase() { return _baseAbleton; }
  QSharedPointer<ableton::AlsAbleton>& getLocal() { return _localAbleton; }
  QSharedPointer<ableton::AlsAbleton>& getRemote() { return _remoteAbleton; }
  QSharedPointer<ableton::AlsAbleton>& getMerge() { return _mergeAbleton; }

private:
  const MeltCommandLine& Arguments;

  QSharedPointer<ableton::AlsAbleton> _baseAbleton;
  QSharedPointer<ableton::AlsAbleton> _localAbleton;
  QSharedPointer<ableton::AlsAbleton> _remoteAbleton;
  QSharedPointer<ableton::AlsAbleton> _mergeAbleton;
};


M_NAMESPACE_APP_END
