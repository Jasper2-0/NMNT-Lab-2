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



Every update OF handles the incoming data via OSC:

    void ofApp::update(){
        while(receiver.hasWaitingMessages()) {
            handleOSC();
        }
    }

A separate function was written to handle the incoming OSC data.

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

handleOSC gets OSC messages from the OSC receiver and passes it along to the appropriate variable defined in OF. 
Quite some copy paste, but it gets the job done.

We’re also watching input on the keyboard. It’s only to get our App to run full-screen, but hey, for thorough documentation:

    void ofApp::keyReleased(int key){
        switch (key) {
            case 'f':
                ofToggleFullscreen();
                break;
                
            default:
                break;
        }
    
    }

With all of that out of the way, let’s have a look at the draw() function, since people would assume that is where most of the action happens…

    void ofApp::draw(){
        ofSetColor(255);
        ofHideCursor();
        shader.begin();
        
        /*
         * move my OSC inputs into the shader
         */
        shader.setUniform1f("c0", c0);

…

        shader.setUniform1f("c15", c15);
        
        /*
         * get the OF time into the shader
         */
        shader.setUniform1f("ofTime", ofGetElapsedTimef());
        
        /*
         * get the screenResolution into the shader
         */
        shader.setUniform2f("ofResolution",ofGetWidth(),ofGetHeight());
        
        ofRect(0, 0, ofGetWidth(), ofGetHeight());
        shader.end();
    
    }

As you can see, nothing much is happening over here, we’re just drawing a rectangle with the size of the screen each frame. However, we _are_ running a shader on that rectangle every frame, see below for more info on how that’s done…


### Midi-controllers into Open Frameworks

Before we get into the intrecacies of shaders, let's look at how OpenFrameworks works. It's a framework written in C++, which means it gets compiled into machinecode when compiling. This is what gives it it tremendous speed (compared to say Processing, although their OpenGL support has improved over the past few releases). However, it also presents a problem, its compile-view-tweak-compile cycle is notably longer than Processing, and that makes it slow to tweak stuff while you're experimenting.

In order to have some parameters to tweak, I figured I could use one of my MIDI controllers. I normally use these for tweaking the parameters of soft-synths (VST's), but why wouldn't they be suited for manipulating the values of shaders? 

OpenFrameworks has support  

#### Enter the Osculator
Osculator is a neat OSX based piece of software that helps with the translation of incoming midi data to 

### Vertex Shader

### Fragment (pixel) Shader 


## Final Product

## References


