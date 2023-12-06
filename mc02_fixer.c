//source: https://gist.github.com/Experiment5X/5025310

#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 
#include <string.h> 
#include <conio.h>


typedef unsigned long DWORD;
typedef unsigned char BYTE;

typedef struct
{
    DWORD magic;        // 0x4D433032, ASCII = "MC02"
    DWORD fileLength;
    DWORD checksum0Length;
    DWORD checksum1Length;
    DWORD checksum0;
    DWORD checksum1;
    DWORD checksum2;

} MC02_Header;

DWORD table[0x100] =
{
        0x00000000, 0x4C11DB7,  0x9823B6E,  0xD4326D9,  0x130476DC, 0x17C56B6B,
	0x1A864DB2, 0x1E475005, 0x2608EDB8, 0x22C9F00F, 0x2F8AD6D6, 0x2B4BCB61,
	0x350C9B64, 0x31CD86D3, 0x3C8EA00A, 0x384FBDBD, 0x4C11DB70, 0x48D0C6C7,
	0x4593E01E, 0x4152FDA9, 0x5F15ADAC, 0x5BD4B01B, 0x569796C2, 0x52568B75,
	0x6A1936C8, 0x6ED82B7F, 0x639B0DA6, 0x675A1011, 0x791D4014, 0x7DDC5DA3,
	0x709F7B7A, 0x745E66CD, 0x9823B6E0, 0x9CE2AB57, 0x91A18D8E, 0x95609039,
	0x8B27C03C, 0x8FE6DD8B, 0x82A5FB52, 0x8664E6E5, 0xBE2B5B58, 0xBAEA46EF,
	0xB7A96036, 0xB3687D81, 0xAD2F2D84, 0xA9EE3033, 0xA4AD16EA, 0xA06C0B5D,
	0xD4326D90, 0xD0F37027, 0xDDB056FE, 0xD9714B49, 0xC7361B4C, 0xC3F706FB,
	0xCEB42022, 0xCA753D95, 0xF23A8028, 0xF6FB9D9F, 0xFBB8BB46, 0xFF79A6F1,
	0xE13EF6F4, 0xE5FFEB43, 0xE8BCCD9A, 0xEC7DD02D, 0x34867077, 0x30476DC0,
	0x3D044B19, 0x39C556AE, 0x278206AB, 0x23431B1C, 0x2E003DC5, 0x2AC12072,
	0x128E9DCF, 0x164F8078, 0x1B0CA6A1, 0x1FCDBB16, 0x18AEB13,  0x54BF6A4,
	0x808D07D,  0xCC9CDCA,  0x7897AB07, 0x7C56B6B0, 0x71159069, 0x75D48DDE,
	0x6B93DDDB, 0x6F52C06C, 0x6211E6B5, 0x66D0FB02, 0x5E9F46BF, 0x5A5E5B08,
	0x571D7DD1, 0x53DC6066, 0x4D9B3063, 0x495A2DD4, 0x44190B0D, 0x40D816BA,
	0xACA5C697, 0xA864DB20, 0xA527FDF9, 0xA1E6E04E, 0xBFA1B04B, 0xBB60ADFC,
	0xB6238B25, 0xB2E29692, 0x8AAD2B2F, 0x8E6C3698, 0x832F1041, 0x87EE0DF6,
	0x99A95DF3, 0x9D684044, 0x902B669D, 0x94EA7B2A, 0xE0B41DE7, 0xE4750050,
	0xE9362689, 0xEDF73B3E, 0xF3B06B3B, 0xF771768C, 0xFA325055, 0xFEF34DE2,
	0xC6BCF05F, 0xC27DEDE8, 0xCF3ECB31, 0xCBFFD686, 0xD5B88683, 0xD1799B34,
	0xDC3ABDED, 0xD8FBA05A, 0x690CE0EE, 0x6DCDFD59, 0x608EDB80, 0x644FC637,
	0x7A089632, 0x7EC98B85, 0x738AAD5C, 0x774BB0EB, 0x4F040D56, 0x4BC510E1,
	0x46863638, 0x42472B8F, 0x5C007B8A, 0x58C1663D, 0x558240E4, 0x51435D53,
	0x251D3B9E, 0x21DC2629, 0x2C9F00F0, 0x285E1D47, 0x36194D42, 0x32D850F5,
	0x3F9B762C, 0x3B5A6B9B, 0x315D626,  0x7D4CB91,  0xA97ED48,  0xE56F0FF,
	0x1011A0FA, 0x14D0BD4D, 0x19939B94, 0x1D528623, 0xF12F560E, 0xF5EE4BB9,
	0xF8AD6D60, 0xFC6C70D7, 0xE22B20D2, 0xE6EA3D65, 0xEBA91BBC, 0xEF68060B,
	0xD727BBB6, 0xD3E6A601, 0xDEA580D8, 0xDA649D6F, 0xC423CD6A, 0xC0E2D0DD,
	0xCDA1F604, 0xC960EBB3, 0xBD3E8D7E, 0xB9FF90C9, 0xB4BCB610, 0xB07DABA7,
	0xAE3AFBA2, 0xAAFBE615, 0xA7B8C0CC, 0xA379DD7B, 0x9B3660C6, 0x9FF77D71,
	0x92B45BA8, 0x9675461F, 0x8832161A, 0x8CF30BAD, 0x81B02D74, 0x857130C3,
	0x5D8A9099, 0x594B8D2E, 0x5408ABF7, 0x50C9B640, 0x4E8EE645, 0x4A4FFBF2,
	0x470CDD2B, 0x43CDC09C, 0x7B827D21, 0x7F436096, 0x7200464F, 0x76C15BF8,
	0x68860BFD, 0x6C47164A, 0x61043093, 0x65C52D24, 0x119B4BE9, 0x155A565E,
	0x18197087, 0x1CD86D30, 0x29F3D35,  0x65E2082,  0xB1D065B,  0xFDC1BEC,
	0x3793A651, 0x3352BBE6, 0x3E119D3F, 0x3AD08088, 0x2497D08D, 0x2056CD3A,
	0x2D15EBE3, 0x29D4F654, 0xC5A92679, 0xC1683BCE, 0xCC2B1D17, 0xC8EA00A0,
	0xD6AD50A5, 0xD26C4D12, 0xDF2F6BCB, 0xDBEE767C, 0xE3A1CBC1, 0xE760D676,
	0xEA23F0AF, 0xEEE2ED18, 0xF0A5BD1D, 0xF464A0AA, 0xF9278673, 0xFDE69BC4,
	0x89B8FD09, 0x8D79E0BE, 0x803AC667, 0x84FBDBD0, 0x9ABC8BD5, 0x9E7D9662,
	0x933EB0BB, 0x97FFAD0C, 0xAFB010B1, 0xAB710D06, 0xA6322BDF, 0xA2F33668,
	0xBCB4666D, 0xB8757BDA, 0xB5365D03, 0xB1F740B4
};

// I have no clue how this works and understand absolutely none of the math behind it.
// I just reversed it from Dead Space 3.
DWORD MC02(const BYTE *pb, DWORD cb)
{
	if (cb < 4)
		return 0;

	DWORD rotatedThird = (pb[2] << 8) | (pb[2] >> 24);
	DWORD ORedFirstPair = ((pb[0] << 24) | (pb[0] >> 8)) | ((pb[1] << 16) | (pb[1] >> 16));

	DWORD seedValue = ~((rotatedThird | ORedFirstPair) | pb[3]);
	pb += 4;
	cb -= 4;

	for (DWORD i = 0; i < cb; i++)
	{
		DWORD lookedUpValue = table[((seedValue >> 22) & 0x3FC) >> 2];
		DWORD insertedNum = pb[i] | (seedValue << 8);
		seedValue = lookedUpValue ^ insertedNum;
	}

	return ~seedValue;
}

byte PC;
/*
DWORD 4b2d(char *4bs)
{
	byte 4b[4];
	sscanf(4bs,"%x %x %x %x",4b[0],4b[1],4b[2],4b[3]);
	DWORD dw = (DWORD)4b;
	return dw;
}
*/
DWORD FlipDword(DWORD dw)
{
    if (PC) return dw;
    DWORD toReturn = 0;

    toReturn |= (dw >> 24);
    toReturn |= (dw >> 8) & 0xFF00;
    toReturn |= (dw << 8) & 0xFF0000;
    toReturn |= (dw << 24);

    return toReturn;
}

float ReverseFloat( const float inFloat )
{
   float retVal;
   char *floatToConvert = ( char* ) & inFloat;
   char *returnFloat = ( char* ) & retVal;

   // swap the bytes into a temporary buffer
   returnFloat[0] = floatToConvert[3];
   returnFloat[1] = floatToConvert[2];
   returnFloat[2] = floatToConvert[1];
   returnFloat[3] = floatToConvert[0];

   return retVal;
}

DWORD ReadDword(FILE *file)
{
    DWORD temp;
    fread(&temp, 4, 1, file);

    // flip it because in the file it's big endian
    return FlipDword(temp);
}

void WriteDword(FILE *file, DWORD dw)
{
    // flip it because in the file it's big endian
    dw = FlipDword(dw);
    fwrite(&dw, 4, 1, file);
}

char*path;

DWORD base;

void fwriteE(void*buf,size_t sz,size_t num,FILE*file,byte LE)
{
	if (LE) {fwrite(buf,sz,num,file);return;}
for (byte n = 0;n<num;n++)
for (byte b = 0;b<sz;b++)
fwrite(buf+n*sz+sz-1-b,1,1,file);
}

void freadE(void*buf,size_t sz,size_t num,FILE*file,byte LE)
{
	if (LE) {fread(buf,sz,num,file);return;}
byte bar[sz*num];
fread(bar,sz,num,file);
//byte bar[sz];
for (byte n = 0;n<num;n++)
for (byte b = 0;b<sz;b++)
*(byte*)(buf + n*sz+ b) = bar[n*sz+sz-1-b];
}

DWORD fscandw(DWORD dw,FILE*save,DWORD start,size_t sz,byte LE)
	{
		//printf("%X found\n",start);
		fseek(save, start, SEEK_SET);
		byte b1,b2;
		for (byte b=0;b<sz;b++)
		{
			DWORD d1;
			freadE(&d1, 4, 1, save, PC);
			b1 = (d1 == dw); 
			if (b1) break;
			//{printf("%X found\n",dw);break;}
		}
		if (!b1) {printf("%X not found\n",dw);return 0;}
		return ftell(save)-4;
	}


void ReadHeader(FILE *file, MC02_Header *header)
{
    // seek to the beginning of the file
    fseek(file, 0 + base, SEEK_SET);

    header->magic = ReadDword(file);
    header->fileLength = ReadDword(file);
    header->checksum0Length = ReadDword(file);
    header->checksum1Length = ReadDword(file);
    header->checksum0 = ReadDword(file);
    header->checksum1 = ReadDword(file);
    header->checksum2 = ReadDword(file);
}

void WriteHeader(FILE *file, MC02_Header *header)
{
    // seek to the beginning of the file
    fseek(file, 0 + base, SEEK_SET);

    WriteDword(file, header->magic);
    WriteDword(file, header->fileLength);
    WriteDword(file, header->checksum0Length);
    WriteDword(file, header->checksum1Length);
    WriteDword(file, header->checksum0);
    WriteDword(file, header->checksum1);
    WriteDword(file, header->checksum2);
}

void Pause()
{
	printf("- Press Any Key. \n"); getch();
	//system("pause");
}

DWORD base;

byte ui=1>0,bdt,qod,lo;

int mc02(int argc, char *argv[])
{
if ((long)base<0) return 0;
FILE *save = fopen(path, "rb+");
if (!save) return 0;
fseek(save, 0 + base, SEEK_SET);
DWORD temp = ReadDword(save);
if (temp != 0x4D433032) {
	printf("Invalid MC02 magic.\n");
	return -1;
}

BYTE headerBuff[0x18];

MC02_Header header;
ReadHeader(save, &header);

// verify the lengths
if (header.fileLength != (header.checksum0Length + header.checksum1Length + 0x1C))
{
	printf("Size mismatch.\n");
	Pause();
	return -1;
}


    // read in the header as a buffer for hashing later
    fseek(save, 0 + base, SEEK_SET);
    fread(headerBuff, 1, 0x18, save);

    // fix the first checksum
    BYTE *checksum0Buffer = malloc(header.checksum0Length);

    fseek(save, 0x1C + base, SEEK_SET);
    fread(checksum0Buffer, 1, header.checksum0Length, save);
    header.checksum0 = MC02(checksum0Buffer, header.checksum0Length);

    free(checksum0Buffer);

    // fix the second checksum
    BYTE *checksum1Buffer = malloc(header.checksum1Length);

    fread(checksum1Buffer, 1, header.checksum1Length, save);
    header.checksum1 = MC02(checksum1Buffer, header.checksum1Length);

    free(checksum1Buffer);

    // fix the last checksum
    *(DWORD*)(headerBuff + 0x10) = FlipDword(header.checksum0);
    *(DWORD*)(headerBuff + 0x14) = FlipDword(header.checksum1);

    header.checksum2 = MC02(headerBuff, 0x18);

    WriteHeader(save, &header);

    fflush(save);
    fclose(save);

    printf("Checksums fixed.\n");
    //if (!qod) Pause();
    return 0;
}

int gf2se(int argc, char *argv[])
{
	FILE *save = fopen(path, "rb+");
	fseek(save, 0x134 + base, SEEK_SET);
	if (ReadDword(save) != 0x87E03A5D)
    {
		printf("%s\n","not gf2. ");
        return -1;
    }

    void money_io(char w)
    {
	//if (!PC) {if (w == 1)printf("PC only, sry");return;}
    float mon; 
    DWORD mnps = 0x1624;        
    fseek(save, mnps+base, SEEK_SET);
    if (w)
        {
            char mns[100];
            printf("!: Input Credits: "); gets(mns);
            mon = atof(mns);
			//if (!PC) mon = ReverseFloat(mon);
            //printf("c: New Cash: %.0f\n", mon);
            fwriteE(&mon, 4, 1, save,PC);                
        }
        else
        {
            freadE(&mon, 4, 1, save, 4);
			//if (!PC) mon = ReverseFloat(mon);
            
        }
    printf("m: Money: %.0f\n", mon);   
    }

    void name_io(char w)
    {
		if (!PC) {if (w == 1) printf("PC only");return;}
        wchar_t nmsd[100];
        DWORD nmps = 0x2034;
        fseek(save, nmps, SEEK_SET);
        //if (mode=='r')    
        if (w == 1)
        {
            printf("Input New Name: "); _getws(nmsd);
            fwrite(nmsd, 2, 50, save);
            wprintf(L"n: Name: %s\n", nmsd);
        }
        else
        {
            fgetws(nmsd, 100, save); wprintf(L"n: Name: %s\n", nmsd);
        }
        return;
    }

    void bd_io(char w)
    {
        DWORD adr = base + 0x144, dw1;
        fseek(save, adr, SEEK_SET);
        		
		dw1 = ReadDword(save);
        byte on = dw1 == 0;
        char c1[10];

        if (w == 1)
        {
            on = !on; dw1 = on ? 0 : 1; 
            fseek(save, adr, SEEK_SET);
            WriteDword(save, dw1);
        }

        {
            strcpy(c1, "OFF");
            if (on) strcpy(c1, "ON");
            printf("b: Beta: Dominic %s\n", c1);
        }
        return;
    }

    void tc_io(char w)
    {
        DWORD adr = base + 0x14FC+0x130; //0x162C
		byte bar[4];
        fseek(save, adr, SEEK_SET);
		freadE(&bar, 1, 4, save, PC);
        byte on = bar[0] == 1;

        if (w == 1)
        {
            on = !on; bar[0] = on ? 1 : 0; 
            fseek(save, adr, SEEK_SET);
            fwriteE(&bar, 1, 4, save, PC);
			//WriteDword(save, dw1);
        }

        {
            /*strcpy(c1, "OFF");
            if (on) strcpy(c1, "ON");*/
            printf("t: TC: Cipolla: %s\n", on?"ON":"OFF");
        }
        return;
    }
	
	DWORD adr_mp = base + 0x14FC-4+0x130; /*3E5C*/
	void lic(byte w)
	{
        fseek(save, adr_mp, SEEK_SET);
		DWORD num = ReadDword(save),sum=0;
		byte b1 = PC ? 0 : 3,b2;
		
		fseek(save, 20, SEEK_CUR);
		if (w)
		{
		printf("!: Input License Level (0-255). 0 - None. 4 - Master.\n"); //* to cancel. \n
			b2 = getch()-'0';
			//scanf("%i", &b2);
		}
		for (byte b = 0;b<num;b++)
		{
			fseek(save, 6*4+16+b1, SEEK_CUR);
		
		if (w)
			fwrite(&b2, 1, 1, save);
		else
		{
			fread(&b2, 1, 1, save);
		}
		
		sum += b2;
		//printf("%x ",ftell(save));
			fseek(save, 4-b1-1, SEEK_CUR);
		}		
		//printf("l: license overriden for %i mobs\n",num);
		if (w)
		printf("l: Licensed %i mobs to lvl %i\n",num,b2);
	printf("l: License Level Summary: %i?\n",sum);
		//  of master obtained for
		//printf("m: master license obtained for %i mobs\n",num);
	}
	
	void hnrs(char w)
	{
		fseek(save, adr_mp, SEEK_SET);
		DWORD num = ReadDword(save);
		if (num<1) {printf("h: Honors: N/A (no crew)");return;}
		fseek(save, 20, SEEK_CUR);
		short h=0;DWORD i;
		if (w)
		{			
			//printf("%s\n","how many Honors you want?"); 			
			printf("%s","!: Input Honors Number : ");  //(0-65535)
			scanf("%hu", &h);
			/*
			while (1)
			{
			scanf("%i", &i);
			printf("%i",i);
			if (i*(i-65535)<0) {h=(short)i;break;}
			}
			*/
		}
		for (byte b = 0;b<num;b++)
		{
			if (!w)
			{freadE(&h, 2, 1, save, PC);break;}
		for (byte b1 = 0;b1<12;b1++)
		{
			fwriteE(&h, 2, 1, save, PC);
		}
		fseek(save, 20, SEEK_CUR);
		}		
		printf("h: Honors: %hu\n", h);
	}
	byte exp1_on = 0;
	void exp1(char w)
	{
		byte on=exp1_on,b1;
		fseek(save, adr_mp+4, SEEK_SET);		
		if (w) {on = !on;b1 = on ? 1 : 0;}
		for (byte b = 0;b<20;b++)
		{
			if (w)
			{
				fwrite(&b1, 1, 1, save);
			}
			else
			{
				fread(&b1, 1, 1, save);
				on = b1 == 1;
				if (!on) break;//{on = 0;break;}
			}			
		}
		printf("%s%s\n","x: TC & Experimental flags: ",on?"ON":"OFF"); //  unknown near TC 
		exp1_on = on;
	}
	
	DWORD crw_sz_pos=0;
	
	byte crw_sz_pos_get()
	{
		DWORD b1 = fscandw(0xB604DD4,save,adr_mp-0x3E5C+0x7F00,0x200,PC); 
		// D4 4D 60 0B
		if (!b1) {return 0;}
		crw_sz_pos = b1+16;
		return 1;
	}
	/*
	byte spec_get()
	{
		DWORD b1 = fscandw(0xB604DD4,save,adr_mp-0x3E5C+0x7F00,0x200,PC); 
		// D4 4D 60 0B
		if (!b1) {return 0;}
		crw_sz_pos = b1+16;
		return 1;
	}
	*/
	void crw_sz(byte w)
	{
		if (!crw_sz_pos) 
			if (!crw_sz_pos_get()) return;
		fseek(save, crw_sz_pos, SEEK_SET);
		DWORD crw_sz;
		if (!w)
		{
			freadE(&crw_sz, 4, 1, save, PC);
		}
		else
		{
			printf("!: Input Family Slots (0-8). * to cancel. \n");
			//char c = getch();
			while (1)
			{
				char c = getch();
				if (c == '*') return;
			crw_sz = c -'0';
			if (crw_sz>=0&&crw_sz<=8) break;
			}
			// todo: input crew size (to free)
			fwriteE(&crw_sz, 4, 1, save, PC);
		}
		printf("f: Family Slots: %i.\n",crw_sz);
	}
	
	void spec(byte w)
	{
		if (!crw_sz_pos) 
			if (!crw_sz_pos_get()) return;
		fseek(save, crw_sz_pos, SEEK_SET);
		DWORD crw_sz,dw1=0xFC;
		freadE(&crw_sz, 4, 1, save, PC);
		fseek(save, 0xD0, SEEK_CUR);
		for (byte b = 0;b<crw_sz;b++)
		{
			fwriteE(&dw1, 4, 1, save,PC);
			fseek(save, 0x50-4, SEEK_CUR);
		}
		printf("s: Multi Spec: ON\n");
	}

void weps(byte w)
{
		printf("w: ");

	fseek(save, adr_mp, SEEK_SET);
	DWORD num = ReadDword(save),tmp,val,i=0,dw1=0xEA,
	// values dumped with CE's $luacode
	dwar[] = {0x52631AAB, 0x3B9DCEA, 0xB5109F29, 0x59BFB800, 0xB167A3F, 0xBC6D3C7E, 0xDAF669BC, 0x8C4D2BFB, 0x3DA3EE3A, 0x214B0EEE, 0xD2A1D12D, 0x83F8936C, 0x3B3317A9, 0xEC89D9E8, 0x9DE09C27, 0x52631AAB, 0x3B9DCEA, 0xB5109F29, 0x59BFB800, 0xB167A3F, 0xBC6D3C7E, 0xDAF669BC, 0x8C4D2BFB, 0x3DA3EE3A, 0x214B0EEE, 0xD2A1D12D, 0x83F8936C, 0x3B3317A9, 0xEC89D9E8, 0x9DE09C27, 0};
	;
	fseek(save, 20+(6*4+16+4)*num, SEEK_CUR);
	//byte b1 = PC ? 0 : 3,b2 = 0xEA;
	while (1)
	{
	//printf("%x:",ftell(save));
	freadE(&tmp, 4, 1, save,PC);
	if (tmp == 0xA8896ED8) {printf("%X:b ",ftell(save)-4);break;}
	freadE(&val, 4, 1, save,PC);
	//printf("%x ",tmp);
	//printf("%x:%x ",ftell(save)-4,tmp);
	if (val != 0)// || val == 1 || (float)val == 1.0) 
		continue;
	
	//printf("%x:%x ",ftell(save),tmp);	
	//printf("%x:",ftell(save));
	//freadE(&tmp, 4, 1, save,PC);
	//printf("%x ",tmp);
	//printf("%x:%x ",ftell(save)-4,tmp);
	byte j=0;
	for (byte b = 0;b<100;b++) 
	{
		DWORD buf = dwar[b];
		if (buf==0) break;
		if (tmp == buf) {
			printf("%X:%X ",ftell(save)-4,buf);
			j = 1;
			break;
		}
	}
	//if (tmp != 0) continue;
	if (!j) continue;
	fseek(save, -4, SEEK_CUR);
	//printf("%x: ",ftell(save));
	//fseek(save, b1, SEEK_CUR);
	//printf("%x:w ",ftell(save));
	//fseek(save, +4, SEEK_CUR);
	fwriteE(&dw1, 4, 1, save,PC);
	//fseek(save, 4-b1-1, SEEK_CUR);
	i++;
	getch();
	}
	printf("uw: filled %i vars\n",i);
}

    name_io(0);
    bd_io(0);
    money_io(0);
	tc_io(0);
	crw_sz(0);
    if (bdt) bd_io(1);
	lic(0);
	//printf("l: Licenses\n");
	hnrs(0);
	//printf("h: Honors\n");
	//printf("x: Experimental\n");
	exp1(0);

	
    if (ui) 
     {
    printf("\n!: Input letter to edit. * when don`.\n\n");
	// literal \n l for license \n 'Enter' to Exit. 

    while (1)
    {
        char b1 = getch();
        if (b1 == '*') break;
        if (b1 == 'n') name_io(1); 
        if (b1 == 'b') bd_io(1);
        if (b1 == 't') tc_io(1);
        if (b1 == 'm') money_io(1);
		if (b1 == 'l') lic(1);
		if (b1 == 'x') exp1(1);
		if (b1 == 'h') hnrs(1);
		if (b1 == 'f') crw_sz(1);
		if (b1 == 'w') weps(1);
		if (b1 == 's') spec(1);
    }
	 }
    fflush(save);    
printf("\n%s\n","Don` GF2 editing. Saved.\n");
fclose(save);
}

byte s3; 

void info()
{
		/*
	printf("\n%s\n%s\n%s\n%s\n",
"Godfather 2 Save Editor",
"Supports both PC and consoles",
"Thanks to TheMobster777 and Pandubreak",
"https://github.com/r3sus/ds1savefix");	
*/
	
	printf("\n\
\n_ Godfather 2 Save Editor\
\nSupports both PC and consoles\
\nhttps://github.com/r3sus/ds1savefix\
\nDedicated to TheMobster777.\nThanks to Pandubreak. \
\nTools used: Beyond Compare;Cheat Engine;010 Editor.\
\n\n");	
Pause();
printf("_ Usage options:\nLaunch exe or \nDrag and drop save on exe or \ncmd: mc02_fixer savePath \n\n");
//[options]\nOptions: b - beta dom, q - quiet fix
//, l - license
}

// checks, GetPlatform
int intro(int argc, char *argv[]) 
{

// 

	/*
	else
    {
		printf("Drag and drop save file here (or paste path): ");
        path = malloc(255);
		scanf("%s",path);
		//gets(path);
		//scanf("%[^\n]%*c", path);
		//printf("%s",path);
    }
	*/
	
    FILE *save = NULL;
	if (path) 
	{
		//printf("path: %s\n",path);
		save = fopen(path, "rb+");
	}
	//printf("path: %s\n",path);
	byte b1 = 1;
    while (!save) 
    {
		//printf("path: %s\n",path);
		if (b1) {path = malloc(255);
        printf("Drag and drop save file here (or paste path): ");
		b1=0;
		}
		else
		printf(" not exists. Try again (* to exit). ");
	gets(path);
	if (path[0]=='*') {//printf(" Exiting.");
	return -1;}
	if (sscanf(path,"%[^\"]",path))
		{
				printf("1: ");
		}
		else if (sscanf(path,"\"%[^\"]\"",path))
			{
				printf("2: ");
			}
			else continue;
	/*
		if (sscanf(path,"%[^\"]",path))
			if (!sscanf(path,"\"%[^\"]\"",path));
				continue;
				*/
		printf("path: %s\n",path);
		//gets(path);
		
		save = fopen(path, "rb+");
    }

	printf("\nFile: \n'%s'\n\n",path);	
	
    DWORD temp; 
    fread(&temp, 4, 1, save);
    if (temp == 0x484D4752) {base = 0x2834; PC=1;} 
    else if (temp == 0x204E4F43) base = 0xD000; // "CON "
    else if (temp == 0xB000000) base = -0x130; // S3    
	else 
	{
        printf("unsupported sig %X\n",temp);
        Pause();
        return -1;	
	}
	fclose(save);
	
	return 1;
}

int args(int argc, char *argv[])
{   
    if (argc >= 2)
	{	
		path = argv[1];
	}
	
    if (argc==3) 
    {
        ui = 0>0;
        char *str = argv[2];
        for (byte b=0;b<sizeof(str);b++)
        {
        char arg = str[b]; 
        if (arg == 'b') bdt = 1;
        if (arg == 'q') qod = 1;
        //if (arg == 'l') lo = 1;
        }
    //printf("%s\n",str);
    //bdt = argv[2][0]=='b';
    }
}

void Exit()
{
	printf("Exiting\n");
	Pause();
}

void bak(int argc, char *argv[])
{
	//CopyFile(argv[1],strcat(argv[1],".copy"),FALSE);
}

int main(int argc, char *argv[])
{
args(argc,argv);
info();
if (!qod) Pause();
while (1)
{
while (intro(argc,argv)!=1) {//printf("err\n");
if (path[0]=='*') {Exit();//printf(" Exiting.");
return -1;}
}//return 0;}
//bak(argc,argv);
gf2se(argc,argv);
mc02(argc,argv);
printf("All done, enjoy!\n");
Pause();
printf("!: Input\n s - operate same save again.\n n - new. \n * - exit.\n");
while (1)
{
	char c = getch();
	if (c=='*') return 1;
	if (c=='s') break;
	if (c=='n') {free(path);//path[0]=0;
	break;}
}
//strcpy(path,"");
}
}