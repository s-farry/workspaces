// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME DictOutput

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "My_double_CB.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_My_double_CB(void *p = 0);
   static void *newArray_My_double_CB(Long_t size, void *p);
   static void delete_My_double_CB(void *p);
   static void deleteArray_My_double_CB(void *p);
   static void destruct_My_double_CB(void *p);
   static void streamer_My_double_CB(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::My_double_CB*)
   {
      ::My_double_CB *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::My_double_CB >(0);
      static ::ROOT::TGenericClassInfo 
         instance("My_double_CB", ::My_double_CB::Class_Version(), "My_double_CB.h", 16,
                  typeid(::My_double_CB), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::My_double_CB::Dictionary, isa_proxy, 16,
                  sizeof(::My_double_CB) );
      instance.SetNew(&new_My_double_CB);
      instance.SetNewArray(&newArray_My_double_CB);
      instance.SetDelete(&delete_My_double_CB);
      instance.SetDeleteArray(&deleteArray_My_double_CB);
      instance.SetDestructor(&destruct_My_double_CB);
      instance.SetStreamerFunc(&streamer_My_double_CB);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::My_double_CB*)
   {
      return GenerateInitInstanceLocal((::My_double_CB*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::My_double_CB*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr My_double_CB::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *My_double_CB::Class_Name()
{
   return "My_double_CB";
}

//______________________________________________________________________________
const char *My_double_CB::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::My_double_CB*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int My_double_CB::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::My_double_CB*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *My_double_CB::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::My_double_CB*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *My_double_CB::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::My_double_CB*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void My_double_CB::Streamer(TBuffer &R__b)
{
   // Stream an object of class My_double_CB.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      RooAbsPdf::Streamer(R__b);
      x.Streamer(R__b);
      mu.Streamer(R__b);
      sig.Streamer(R__b);
      a1.Streamer(R__b);
      n1.Streamer(R__b);
      a2.Streamer(R__b);
      n2.Streamer(R__b);
      R__b.CheckByteCount(R__s, R__c, My_double_CB::IsA());
   } else {
      R__c = R__b.WriteVersion(My_double_CB::IsA(), kTRUE);
      RooAbsPdf::Streamer(R__b);
      x.Streamer(R__b);
      mu.Streamer(R__b);
      sig.Streamer(R__b);
      a1.Streamer(R__b);
      n1.Streamer(R__b);
      a2.Streamer(R__b);
      n2.Streamer(R__b);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_My_double_CB(void *p) {
      return  p ? new(p) ::My_double_CB : new ::My_double_CB;
   }
   static void *newArray_My_double_CB(Long_t nElements, void *p) {
      return p ? new(p) ::My_double_CB[nElements] : new ::My_double_CB[nElements];
   }
   // Wrapper around operator delete
   static void delete_My_double_CB(void *p) {
      delete ((::My_double_CB*)p);
   }
   static void deleteArray_My_double_CB(void *p) {
      delete [] ((::My_double_CB*)p);
   }
   static void destruct_My_double_CB(void *p) {
      typedef ::My_double_CB current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_My_double_CB(TBuffer &buf, void *obj) {
      ((::My_double_CB*)obj)->::My_double_CB::Streamer(buf);
   }
} // end of namespace ROOT for class ::My_double_CB

namespace {
  void TriggerDictionaryInitialization_DictOutput_Impl() {
    static const char* headers[] = {
"My_double_CB.h",
0
    };
    static const char* includePaths[] = {
"/cvmfs/sft.cern.ch/lcg/releases/ROOT/6.06.00-a82d7/x86_64-slc6-gcc49-opt/include",
"/user2/sfarry/workspaces/momentumscale/src/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "DictOutput dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(Your description goes here...)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$My_double_CB.h")))  My_double_CB;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "DictOutput dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "My_double_CB.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"My_double_CB", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("DictOutput",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_DictOutput_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_DictOutput_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_DictOutput() {
  TriggerDictionaryInitialization_DictOutput_Impl();
}
