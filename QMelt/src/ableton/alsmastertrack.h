#pragma once

// ABLETON
#include "src/ableton/alstrack.h"

M_FORWARD_ABLETON(AlsMasterChain)

M_NAMESPACE_ABLETON_BEGIN


class AlsMasterTrack : public AlsTrack
{
public:
  AlsMasterTrack(QObject *parent);
  ~AlsMasterTrack();


  void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);

  /// <summary>
  /// Creates the device chain.
  /// </summary>
  /// <returns></returns>
  QSharedPointer<QObject> createMasterChain();


  QSharedPointer<AlsMasterChain> MasterChain;

private:
};


M_NAMESPACE_ABLETON_END
