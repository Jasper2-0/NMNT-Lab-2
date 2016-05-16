     _____              _______           __ __        
    |   | |----.-.-.-. |   |   |.-----.--|  |__|.---.-.
    |     | -__| | | | |       ||  -__|  _  |  ||  _  |
    |_|___|____|_____| |__|_|__||_____|_____|__||___._|
     _____              _______              __                __                   
    |   | |----.-.-.-. |_     _|.-----.----.|  |--.----.----.|  |.-----.-----.--.--.
    |     | -__| | | |   |   |  |  -__|  __||     |    |  _ ||  ||  _  |  _  |  |  |
    |_|___|____|_____|   |___|  |_____|____||__|__|_|__|____||__||_____|___  |___  |
                                                                       |_____|_____|
    Leiden University 2016 // Peter van der Putten // Jeroen Oorschot


# Lab 2 Openframeworks -- Experimenting with Signed Distance Fields

## What is it?
For this assignment I experimented with raymarching signed distance fields. A methodology for creating graphics with pixel shaders that run on the GPU of your computer.

For people not wel versed in coder-geek speak; A fancy screensaver with pretty colors and tunnels. 


## How was it created?

### Setup in OpenFrameworks
The main functions of the standard open frameworks apps that were used were setup(), update(), and keyReleased(). To handle the incoming OSC data a handleOSC() function was written.

    void ofApp::setup(){
        cout << "listening for osc messages on port " << PORT << "\n";
        receiver.setup(PORT);
        ofSetFrameRate(60);
    
        #ifdef TARGET_OPENGLES
        shader.load("shadersES2/shader");
        #else
        if(ofIsGLProgrammableRenderer()){
            shader.load("shadersGL3/shader");
        }else{
            shader.load("shadersGL2/shader");
        }
    #endif
    
    }



The main setup functions takes care of the following housekeeping bits:
- It sets up OF (receiver) for listening to OSC messages on its server
- Sets the framerate to a snappy 60 frames a second
- Loads the appropriate shader based on TARGET_OPENGLES (different GPU’s use different versions of OpenGL)

    void ofApp::update(){
        while(receiver.hasWaitingMessages()) {
            handleOSC();
        }
    }

Every update OF handles the incoming data via OSC

    void ofApp::handleOSC() {
        ofxOscMessage m;
        receiver.getNextMessage(m);
        cout << m.getArgAsFloat(0) << "\n";
        
        /*
         * Yes, I'm a aware that this is a ton of copy-paste. it gets the job done though ^_^
         */
        
        if (m.getAddress() == "/midi/cc21/9") {
            c0 = m.getArgAsFloat(0);
        }
        
…       
        
        if (m.getAddress() == "/midi/cc48/9") {
            c15 = m.getArgAsFloat(0);
        }
    }

handleOSC gets OSC messages from the OSC receiver and passes it along to the appropriate variable defined in OF. Quite some copy paste, but it gets the job done.


### Midi-controllers into Open Frameworks

#### Enter the Osculator
Osculator is a neat OSX based piece of software that helps with the translation of incoming midi data to 

### Vertex Shader

### Fragment (pixel) Shader 


## Final Product

## References


