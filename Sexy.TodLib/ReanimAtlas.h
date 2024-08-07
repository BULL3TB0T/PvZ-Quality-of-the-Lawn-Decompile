#ifndef __REANIMATLAS_H__
#define __REANIMATLAS_H__

#include "../SexyAppFramework/Rect.h"
using namespace Sexy;

#define MAX_REANIM_IMAGES 64

class ReanimatorDefinition;
namespace Sexy
{
    class Image;
    class MemoryImage;
};

class ReanimAtlasImage
{
public:
    int                             mX;
    int                             mY;
    int                             mWidth;
    int                             mHeight;
    Image*                          mOriginalImage;

public:
    ReanimAtlasImage() : mX(0), mY(0), mWidth(0), mHeight(0), mOriginalImage(nullptr){ }
};

bool                                sSortByNonIncreasingHeight(const ReanimAtlasImage& image1, const ReanimAtlasImage& image2);

class ReanimAtlas
{
public:
    ReanimAtlasImage                mImageArray[MAX_REANIM_IMAGES];     
    int                             mImageCount;                        
    MemoryImage*                    mMemoryImage;                       

public:
    ReanimAtlas();

    void                            ReanimAtlasCreate(ReanimatorDefinition* theReanimDef);
    void                            ReanimAtlasDispose();
    /*inline*/ void                 AddImage(Image* theImage);
    /*inline*/ int                  FindImage(Image* theImage);
    bool                            ImageFits(int theImageCount, const Rect& rectTest, int theMaxWidth);
    bool                            ImageFindPlaceOnSide(ReanimAtlasImage* theAtlasImageToPlace, int theImageCount, int theMaxWidth, bool theToRight);
    /*inline*/ bool                 ImageFindPlace(ReanimAtlasImage* theAtlasImageToPlace, int theImageCount, int theMaxWidth);
    /*inline*/ bool                 PlaceAtlasImage(ReanimAtlasImage* theAtlasImageToPlace, int theImageCount, int theMaxWidth);
    int                             PickAtlasWidth();
    void                            ArrangeImages(int& theAtlasWidth, int& theAtlasHeight);
    ReanimAtlasImage*               GetEncodedReanimAtlas(Image* theImage);
    void                            ReloadMemoryImage(int theWidth, int theHeight);
};

MemoryImage*                        ReanimAtlasMakeBlankMemoryImage(int theWidth, int theHeight);
void                                ReloadReanimationAtlases();

#endif
