#version 150

uniform float c0,c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13,c14,c15;

uniform float ofTime;
uniform vec2 ofResolution;

out vec4 fragColor;

const float PI=3.14159265358979323846;

float speed=ofTime*1.5;

float p_x= 2*cos(PI + speed*0.25);
float p_y= -0.5;
float p_z= 2+speed*0.5;

vec2 rotate(vec2 k,float t)
{
    return vec2(cos(t)*k.x-sin(t)*k.y,sin(t)*k.x+cos(t)*k.y);
}

float obj(vec3 p)
{
    float ball_p=1.0;
    float ball_w=ball_p*(0.6650-0.075*0.02);
    float ball=length(mod(p,ball_p)-ball_p*0.5)-ball_w;
    
    float hole_w=ball_p*(0.825);
    float hole=length(mod(p,ball_p)-ball_p*0.5)-hole_w;
 
    
    
    
//    return length(p)-ball_w;
    
    return max(-ball,hole);
    
}

void main()
{
    vec2 position=(gl_FragCoord.xy/ofResolution.xy);
    vec2 aspectRatio = vec2(ofResolution.x/ofResolution.y,1.0); // aspect ratio so we're nice and square on every resolution
    vec2 p=-1.0+2.0*position; // limit range to -1 ... +1;

    vec3 vp=normalize(vec3(p*aspectRatio,0.80)); // screen ratio (x,y) fov (z) (viewport)

    vp.xy=rotate(vp.xy,speed*0.5);	// rotate along z
    

    vec3 ray=vec3(p_x,p_y,p_z);
    
    float t=0.0;
    
    const int ray_n=96;
    
    for(int i=0;i<ray_n;i++)
    {
        float k=obj(ray+vp*t);
        if(abs(k)<0.002) break;
        t+=k*0.7;
    }
    vec3 hit=ray+vp*t;
    
    vec2 h=vec2(-0.05,0.05); // light
    
    vec3 n=normalize(vec3(obj(hit+h.xyy),obj(hit+h.yxx),obj(hit+h.yyx)));
    
    float c=(n.x+n.y+n.z)*0.08+t*0.16; // shade
    
    float color=-0.25*cos(PI*position.x*2.0)+0.25*sin(PI*position.y*4.0);
    
    float r = c*1.25-color;
    float g = c*1.25;
    float b = c*1.5+color;
    float a = 1.0;
    
    fragColor=vec4(vec3(r,g,b)*c,a);

}