#pragma once


/*****************************************************************************/
/**

Abstract interface class for discrete systems in open modelica.

\date     October, 1st, 2008
\author   

*/

/*****************************************************************************
Copyright (c) 2008, OSMC
*****************************************************************************/

typedef std::map<double,unsigned long> event_times_type;
class IEvent
{
public:

    virtual ~IEvent()    {};

    /// Provide number (dimension) of zero functions
    virtual int getDimZeroFunc() = 0;
    /// Provides current values of root/zero functions
    virtual void giveZeroFunc(double* f) = 0;
    virtual bool checkConditions(const bool* events, bool all) = 0;
  
  virtual void saveDiscreteVars() = 0;
    /// Called to handle an event 
    virtual void handleEvent(const bool* events) = 0;
    ///Checks if a discrete variable has changed and triggered an event, returns true if a second event iteration is needed
    virtual bool checkForDiscreteEvents() = 0;    
    
};

