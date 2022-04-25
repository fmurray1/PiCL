#ifndef _picl_h
#define _picl_h

#include <circle/multicore.h>
#include <circle/screen.h>
#include <circle/memory.h>
#include <circle/types.h>

class PiLifeCounter
#ifdef ARM_ALLOW_MULTI_CORE
	: public CMultiCoreSupport
#endif
{
    public:
        PiLifeCounter (CScreenDevice *pScreen, CMemorySystem *pMemorySystem);
        ~PiLifeCounter (void);
	
#ifndef ARM_ALLOW_MULTI_CORE
		boolean Initialize (void)	{ return TRUE; }
	#endif        
        void Run(unsigned nCores);

    private:
	    CScreenDevice *m_pScreen;
};
#endif
