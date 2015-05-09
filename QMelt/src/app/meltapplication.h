#pragma once
#include "common.h"

// QT
#include <QApplication>
#include <QSharedPointer>


M_FORWARD_ABLETON(AlsAbleton)


M_NAMESPACE_APP_BEGIN


class MeltCommandLine;
/*!
 * \brief The MeltApplication class
 */
class MeltApplication : public QApplication
{
public:
  explicit MeltApplication(int argc, char* argv[]);
  ~MeltApplication();

  
  
  
  void processArguments();

  /*!
   * \brief Command line arguments
   */
  QSharedPointer<const MeltCommandLine> Arguments;


  QSharedPointer<ableton::AlsAbleton>& getBase() { return _baseAbleton; }
  QSharedPointer<ableton::AlsAbleton>& getLocal() { return _localAbleton; }
  QSharedPointer<ableton::AlsAbleton>& getRemote() { return _remoteAbleton; }
  QSharedPointer<ableton::AlsAbleton>& getMerge() { return _mergeAbleton; }

private:
  QSharedPointer<ableton::AlsAbleton> _baseAbleton;
  QSharedPointer<ableton::AlsAbleton> _localAbleton;
  QSharedPointer<ableton::AlsAbleton> _remoteAbleton;
  QSharedPointer<ableton::AlsAbleton> _mergeAbleton;
};


M_NAMESPACE_APP_END
