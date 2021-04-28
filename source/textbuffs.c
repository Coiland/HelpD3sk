#include "textbuffs.h"
#include "foldcreation.h"
C2D_TextBuf nameBuf;
/*
*This array is for the main page buttons. To add a button add a column to the row. Give it a name
* and a description to be displayed on the screen.
*/
main_struct the_head_array[] =
    {
        {"this is the ", "does things"},
        {"second", "does things2"},
        {"third", "does things3"},
        {"fourth", "does things4"},
        {"fifth", "does things"},
        {"six", "does things"},
        {"seven", "does things"},
};
/*
*This array is for the sub page buttons. First column is to diplay the information that will be displayed on the button.
*Second column is to attach the button to a parent button from the main page (See the names above to attach).
*Third column is to display the text of the button once clicked.
*/
sub_struct the_sub_array[] =
    {
        {"mombo", "second", "The history of the 3ds is "},
        {"mom", "second", "The place you want to be, is here, this is an experience not a a show, "
                          "this is meant for people like you and menow i dont want to put any predjucide on you or "
                          "anyone for that matter but this experience has lead me to unimaginable circumsstances which "
                          "I could not fathom, thiss is life changing I am no longer a man of god but a man of many words "
                          "a preservation this is history in the making  we are the people of god, worship, love , live... you "
                          "only have one life"
                          "this is meant for people like you and menow i dont want to put any predjucide on you or "
                          "anyone for that   matter but this experience has lead me to unimaginable circumsstances which "
                          "I could not fathom, thiss is life changing I am no longer a man of god but a man of many words "
                          "a preservation this is history in the making  we are the people of god, worship, love , live... you "
                          "only have one life"
                          "The place you want to be, is here, this is an experience not a a show, "
                          "this is meant for people like you and menow i dont want to put any predjucide on you or "
                          "anyone for that matter but this experience has lead me to unimaginable circumsstances which "
                          "I could not fathom, thiss is life changing I am no longer a man of god but a man of many words "
                          "a preservation this is history in the making  we are the people of god, worship, love , live... you "
                          "only have one life"
                          "this is meant for people like you and menow i dont want to put any predjucide on you or "
                          "anyone for that   matter but this experience has lead me to unimaginable circumsstances which "
                          "I could not fathom, thiss is life changing I am no longer a man of god but a man of many words "
                          "a preservation this is history in the making  we are the people of god, worship, love , live... you "
                          "only have one life"
                          "The place you want to be, is here, this is an experience not a a show, "
                          "this is meant for people like you and menow i dont want to put any predjucide on you or "
                          "anyone for that matter but this experience has lead me to unimaginable circumsstances which "
                          "I could not fathom, thiss is life changing I am no longer a man of god but a man of many words "
                          "a preservation this is history in the making  we are the people of god, worship, love , live... you "
                          "only have one life"
                          "this is meant for people like you and menow i dont want to put any predjucide on you or "
                          "anyone for that   matter but this experience has lead me to unimaginable circumsstances which "
                          "I could not fathom, thiss is life changing I am no longer a man of god but a man of many words "
                          "a preservation this is history in the making  we are the people of god, worship, love , live... you "
                          "only have one life"},
        {"mom", "second", "The place you want to be"},
        {"mom", "second", "The place you want to be"},
        {"mom", "second", "The place you want to be"},
        {"mom", "second", "The place you want to be"},
        {"mom", "second", "The place you want to be"},
        {"mom", "third", "The place you want to be in the third column"}};
void createFolders()
{
    nameBuf = C2D_TextBufNew(50);
    for (u8 i = 0; i < ((sizeof(the_head_array)) / sizeof(the_head_array[0])); i++)
    {
        addfolderhead(the_head_array[i].name, the_head_array[i].text);
    }
    for (u8 i = 0; i < ((sizeof(the_sub_array)) / sizeof(the_sub_array[0])); i++)
    {
        addfolder(the_sub_array[i].name, the_sub_array[i].head, the_sub_array[i].text);
    }
}
