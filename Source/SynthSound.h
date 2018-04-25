/*
  ==============================================================================

    SynthSound.h
    Created: 29 Jan 2018 1:51:33pm
    Author:  Jeremy Kaufman

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SynthSound : public SynthesiserSound 
{
    public: 
    bool appliesToNote(int /*midiNoteNumber*/){
            return true;
    }
    bool appliesToChannel(int /*midichannel*/){
            return true;
    }
    
        


};
