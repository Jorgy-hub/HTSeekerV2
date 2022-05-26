# include "HTSeeker.h"

void HTSeekerV2::Initialize(int mode = AC) {
    if(mode != AC && mode != DC)
        static_assert(false, "Mode should be AC or DC");
    
    int HTSeekerV2::Mode = mode;
    
    Wire.begin();
    Wire.beginTransmission(HTSeekerV2::Address);
    Wire.write(0x00);
    Wire.endTransmission();
    
    boolean Verification = Verify();
    static_assert(Verification, "That isn't a HT InfraRed Seeker V2");

    while(Wire.available() > 0)
        Wire.read();  
};

void HTSeekerV2::WireRead( byte Address, byte* buffer ) {   
    Wire.begin();
    Wire.beginTransmission(Address);
    Wire.endTransmission();
    Wire.requestFrom(HTSeekerV2::Address, 6);
    
    while(Wire.available() < 6)
	    for(byte i = 0; i < 6; i++) 
		    buffer[i] = Wire.read();

	while(Wire.available() > 0)
	    Wire.read();
};

boolean HTSeekerV2::Verify() {
    Wire.beginTransmission(HTSeekerV2::Address);
    Wire.write(0x08);
    Wire.endTransmission();
    Wire.requestFrom(HTSeekerV2::Address, 16);

    char Verification[16];
    while(Wire.available() < 16);
        for(byte i = 0; i < 16; i++) 
            Verification[i] = Wire.read();

    return strncmp(Verification, "HiTechncNewIRDir") == 0;
};

IR_Result HTSeekerV2::Read() {
    byte buffer[6];

    if( HTSeekerV2::Mode == DC)
        HTSeekerV2::WireRead(0x42, buffer);
    else if( HTSeekerV2::Mode == AC)
        HTSeekerV2::WireRead(0x49, buffer);

    return Results( buffer );
};

IR_Result HTSeekerV2::Results( byte* buffer ) {
    IR_Result Response;
    if( buffer[0] != 0)
        if(buffer[0] % 2 == 0)
            Response.Strength = (buffer[buffer[0] / 2] + buffer[buffer[0] / 2 + 1]) / 2;
        else 
            Response.Strength = buffer[buffer[0] / 2 + 1];
    else 
        Response.Strength = 0;

    return Response;
};