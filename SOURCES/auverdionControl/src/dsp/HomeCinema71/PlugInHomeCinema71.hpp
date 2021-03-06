#ifndef QPLUGINHOMECINEMA71_H
#define QPLUGINHOMECINEMA71_H

#include <QWidget>
#include <QHBoxLayout>
#include <QString>

#include "vektorraum.h"

#include "freeDSP-Aurora.hpp"
#include "DspPlugIn.hpp"

class CPlugInHomeCinema71 : public CDspPlugin
{

public:
  explicit CPlugInHomeCinema71( Vektorraum::tfloat samplerate );
  virtual ~CPlugInHomeCinema71( void );

  //============================================================================
  /*!
   *
   */
  virtual unsigned int getNumChannels( void ) { return 8; }

  //============================================================================
  /*!
   *
   */
  virtual tDspChannel getGuiForChannel( unsigned int chn, Vektorraum::tfloat fs, CFreeDspAurora* ptrdsp, QWidget* parent );

  //============================================================================
  /*!
   *
   */
  virtual QString getChannelName( unsigned int channel )
  {
    if( channel == 0 )
      return QString( "Front Left" );
    else if( channel == 1 )
      return QString( "Front Right" );
    else if( channel == 2 )
      return QString( "Front Center" );
    else if( channel == 3 )
      return QString( "Rear Left" );
    else if( channel == 4 )
      return QString( "Rear Right" );
    else if( channel == 5 )
      return QString( "Side Left" );
    else if( channel == 6 )
      return QString( "Side Right" );
    else if( channel == 7 )
      return QString( "LFE" );
    else
      return QString( "" );
  }

  //============================================================================
  /*!
   *
   */
  virtual void setMasterVolume( double val, bool doSend );

  //============================================================================
  /*!
   *
   */
  virtual double getMasterVolume( void )
  {
    return masterVolume;
  }

  //============================================================================
  /*!
   *
   */
  virtual uint16_t getAddressMasterVolume( void );

  //============================================================================
  /*!
   *
   */
  virtual uint32_t getPid( void )
  {
    return CFreeDspAurora::PLUGIN_HOMECINEMA71;
  }

  //============================================================================
  /*!
   *
   */
  virtual void setEnableVolumePoti( bool val, bool doSend );

  //============================================================================
  /*! Get the parameters in DSP format. The parameters are returned with register 
   *  address followed by value dword ready to be sent via i2c to DSP.
   *
   * \return Byte array with parameters for DSP. 
   */
  QByteArray getDspParams( void );

  //============================================================================
  //
  // Member Variables
  //
  //============================================================================

};

#endif
