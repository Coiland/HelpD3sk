#include "textbuffs.h"
#include "foldcreation.h"
C2D_TextBuf nameBuf;

typedef struct name_text
{
    char* name;
    char* text;
}name_text;

name_text the_head_array[]=
{
    {"this is the ", "does things"},
    {"second","does things"},
    {"third","does things"},
    {"fourth","does things"},
    {"fifth","does things"},
    {"six","does things"},
    {"seven","does things"},
};

name_text the_sub_array[]=
{
    {"mombo", "second"},
    {"mom", "second"},
    {"mom", "second"},
    {"mom", "second"},
    {"mom", "second"},
    {"mom", "second"},
    {"mom", "second"},
    {"mom", "third"}
};
void createFolders()
{
	nameBuf = C2D_TextBufNew(4096);
    for(u8 i=0; i<((sizeof(the_head_array))/sizeof(the_head_array[0]));i++)
    {
        addfolderhead(the_head_array[i].name,the_head_array[i].text);
    }
    for(u8 i=0; i<((sizeof(the_sub_array))/sizeof(the_sub_array[0]));i++)
    {
        addfolder(the_sub_array[i].name,the_sub_array[i].text);
    }
}
// void createFolders()
// {
// 	nameBuf = C2D_TextBufNew(4096);

// 	addfolderhead("this is the ", "does things");
// 	addfolderhead("second","does things");
// 	addfolderhead("third","does things");
// 	addfolderhead("fourth","does things");
// 	addfolderhead("fifth","does things");
// 	addfolderhead("six","does things");
// 	addfolderhead("seven","does things");
	
// 	addfolder("mombo", "second");
// 	addfolder("mom", "second");
// 	addfolder("mom", "second");
// 	addfolder("mom", "second");
// 	addfolder("mom", "second");
// 	addfolder("mom", "second");
// 	addfolder("mom", "second");
// 	addfolder("mom", "third");
// }