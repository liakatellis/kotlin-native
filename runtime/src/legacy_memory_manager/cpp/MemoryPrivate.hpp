/*
 * Copyright 2010-2017 JetBrains s.r.o.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef RUNTIME_MEMORYPRIVATE_HPP
#define RUNTIME_MEMORYPRIVATE_HPP

#include "Memory.h"

extern "C" {

#define MODEL_VARIANTS(returnType, name, ...)            \
   returnType name##Strict(__VA_ARGS__) RUNTIME_NOTHROW; \
   returnType name##Relaxed(__VA_ARGS__) RUNTIME_NOTHROW;

OBJ_GETTER(AllocInstanceStrict, const TypeInfo* type_info) RUNTIME_NOTHROW;
OBJ_GETTER(AllocInstanceRelaxed, const TypeInfo* type_info) RUNTIME_NOTHROW;

OBJ_GETTER(AllocArrayInstanceStrict, const TypeInfo* type_info, int32_t elements);
OBJ_GETTER(AllocArrayInstanceRelaxed, const TypeInfo* type_info, int32_t elements);

OBJ_GETTER(InitInstanceStrict,
    ObjHeader** location, const TypeInfo* typeInfo, void (*ctor)(ObjHeader*));
OBJ_GETTER(InitInstanceRelaxed,
    ObjHeader** location, const TypeInfo* typeInfo, void (*ctor)(ObjHeader*));

OBJ_GETTER(InitSharedInstanceStrict,
    ObjHeader** location, const TypeInfo* typeInfo, void (*ctor)(ObjHeader*));
OBJ_GETTER(InitSharedInstanceRelaxed,
    ObjHeader** location, const TypeInfo* typeInfo, void (*ctor)(ObjHeader*));

MODEL_VARIANTS(void, SetStackRef, ObjHeader** location, const ObjHeader* object);
MODEL_VARIANTS(void, SetHeapRef, ObjHeader** location, const ObjHeader* object);
MODEL_VARIANTS(void, ZeroStackRef, ObjHeader** location);
MODEL_VARIANTS(void, UpdateStackRef, ObjHeader** location, const ObjHeader* object);
MODEL_VARIANTS(void, UpdateHeapRef, ObjHeader** location, const ObjHeader* object);
MODEL_VARIANTS(void, UpdateHeapRefIfNull, ObjHeader** location, const ObjHeader* object);
MODEL_VARIANTS(void, UpdateReturnRef, ObjHeader** returnSlot, const ObjHeader* object);
MODEL_VARIANTS(void, EnterFrame, ObjHeader** start, int parameters, int count);
MODEL_VARIANTS(void, LeaveFrame, ObjHeader** start, int parameters, int count);

MODEL_VARIANTS(void, ReleaseHeapRef, const ObjHeader* object);
MODEL_VARIANTS(void, ReleaseHeapRefNoCollect, const ObjHeader* object);

}  // extern "C"

#endif // RUNTIME_MEMORYPRIVATE_HPP
