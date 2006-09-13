/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

// $Id$
// $MpId: AliMpPadIteratorPtr.h,v 1.7 2006/05/24 13:58:07 ivana Exp $

/// \ingroup basic
/// \class AliMpPadIteratorPtr
/// \brief  A pointer to the virtual pad iterator;
///
/// It enables to allocate the virtual pad iterator on stack.
/// Usage:                                                                 \n
/// AliMpVIndexed* myIndexed = MyIndexed();                                \n
/// MVIterator& it = *AliMpPadIteratorPtr(myIndexed->CreateIterator());    \n
///
/// \author David Guez, Ivana Hrivnacova; IPN Orsay

#ifndef ALI_MP_PAD_ITERATOR_PTR_H
#define ALI_MP_PAD_ITERATOR_PTR_H

#include <TObject.h>

class AliMpVPadIterator;

class AliMpPadIteratorPtr : public TObject
{
  public:
    AliMpPadIteratorPtr(AliMpVPadIterator* it);
    // AliMpPadIteratorPtr(const AliMpPadIteratorPtr& right); --> private
    virtual ~AliMpPadIteratorPtr();
  
    AliMpVPadIterator* operator->() { return  fIterator; }
    AliMpVPadIterator& operator*()  { return *fIterator; }

  private:   
    AliMpPadIteratorPtr(const AliMpPadIteratorPtr& right);

    // operators
    AliMpPadIteratorPtr& operator=(const AliMpPadIteratorPtr& right);
        // copy and assignment are disallowed to avoid
        // multiple deletion of fIterator

    // data members
    AliMpVPadIterator*  fIterator; ///< The pad iterator
     
  ClassDef(AliMpPadIteratorPtr,1) // Pointer to abstract pad iterator
};

#endif // ALI_MP_PAD_ITERATOR_PTR_H
