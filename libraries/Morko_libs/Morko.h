/*
  Test.h - Test library for Wiring - description
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// ensure this library description is only included once
#ifndef Test_h
#define Test_h

// include types & constants of Wiring core API
#include "WConstants.h"

// library interface description
class Morko
{
  // user-accessible "public" interface
  public:
    MorkoMode(int);
    void setPWMduties(int, int);

  // library-accessible "private" interface
  private:
    int mode;
    void doSomethingSecret(void);
};

#endif

