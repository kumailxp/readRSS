//============================================================================
// Name        : rssreader.cpp
// Author      : Kumail
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <curl/curl.h> //your directory may be different
#include <curl/easy.h>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

string data; //will hold the url's contents

size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up)
{ //callback must have this declaration
    //buf is a pointer to the data that curl has for us
    //size*nmemb is the size of the buffer

    for (int c = 0; c<size*nmemb; c++)
    {
        data.push_back(buf[c]);
    }
    return size*nmemb; //tell curl how many bytes we handled
}

// Define our struct for accepting LCs output
struct BufferStruct
{
char * buffer;
size_t size;
};

// This is the function we pass to LC, which writes the output to a BufferStruct
static size_t WriteMemoryCallback (void *ptr, size_t size, size_t nmemb, void *data)
{
	size_t realsize = size * nmemb;

	struct BufferStruct * mem = (struct BufferStruct *) data;

	mem->buffer = (char *)realloc(mem->buffer, mem->size + realsize + 1);

	if ( mem->buffer )
	{
		memcpy( &( mem->buffer[ mem->size ] ), ptr, realsize );
		mem->size += realsize;
		mem->buffer[ mem->size ] = 0;
	}
	return realsize;
}


int main()
{
//    CURL* curl; //our curl object
//
//    struct BufferStruct output; // Create an instance of out BufferStruct to accept LCs output
//    output.buffer = NULL;
//    output.size = 0;
//
//    curl_global_init(CURL_GLOBAL_ALL); //pretty obvious
//    curl = curl_easy_init();
//
//    curl_easy_setopt(curl, CURLOPT_URL, "http://www.findyourfate.com/rss/horoscope-astrology-feed.asp?mode=view&todate=8/20/2015");
//    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &WriteMemoryCallback);
//    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&output);
//    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress
//
//    curl_easy_perform(curl);
//    curl_easy_cleanup(curl);
//
//    FILE * fp;
//    fp = fopen( "example.xml","w");
//    cout<<"HEILL!";
//    if( !fp )
//    	return 1;
//    fprintf(fp, output.buffer );
//    fclose( fp );
//
//    if( output.buffer )
//    {
//    	free ( output.buffer );
//    	output.buffer = 0;
//    	output.size = 0;
//    }
//
//    cin.get();
    XMLDocument doc;
    doc.LoadFile("example.xml");
    cout<< "ERROR ID: "<<doc.ErrorName()<<endl;

    XMLNode * pRoot = doc.FirstChild();
    if (pRoot ==NULL)
    	cout<<"ERROR!!!"<<endl;

   XMLNode* SiblingNode = pRoot->NextSibling();
   XMLNode* ChildNode = SiblingNode->FirstChild();

   XMLElement *ChildElmt = ChildNode->ToElement();
   string strTagName = ChildElmt->Name();
   cout<<strTagName<<endl;

   XMLNode* Child_2_Node = ChildNode->FirstChild();
   XMLElement *Child_2_NodeElmt = Child_2_Node->ToElement();

   strTagName = Child_2_NodeElmt->Name();
   cout<<strTagName<<endl;

   strTagName = Child_2_NodeElmt->GetText();
   cout<<strTagName<<endl;

   XMLNode* secSibling = Child_2_Node->NextSibling();
   XMLElement *Sib_2_NodeElmt = secSibling->ToElement();

  strTagName = Sib_2_NodeElmt->Name();
  cout<<strTagName<<endl;

  strTagName = Sib_2_NodeElmt->GetText();
     cout<<strTagName<<endl;

   //XMLElement* pElement = pRoot->ToElement();
   //if (pElement ==NULL)
    //      	cout<<"ERROR"<<endl;

//  XMLElement * pElement = pRoot->FirstChildElement("rss")->FirstChildElement("channel");
//  if (pElement ==NULL)
//       	cout<<"ERROR"<<endl;


//    if (pElement ==NULL)
//     	cout<<"ERROR"<<endl;
//    const char* title = pElement->GetText();
//	printf( "Name of play (1): %s\n", title );


//    cout << endl <<  pElement->GetText() << endl;
    //cin.get();







    //curl_global_cleanup();

    return 0;
}
