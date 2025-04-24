//===----------------------------------------------------------------------===//
//===--- MisraTidyModule.h - clang-tidy -------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "../ClangTidy.h"
#include "../ClangTidyModule.h"
#include "../ClangTidyModuleRegistry.h"
#include "ArrayDeclarationCheck.h"

using namespace clang::ast_matchers;

namespace clang::tidy {
namespace misra {

/// This module is for Zircon-specific checks.
class MisraModule : public ClangTidyModule {
public:
  void addCheckFactories(ClangTidyCheckFactories &CheckFactories) override {
    CheckFactories.registerCheck<ArrayDeclarationCheck>(
        "misra-array-declaration");
  }
};

// Register the MisraModule using this statically initialized variable.
static ClangTidyModuleRegistry::Add<MisraModule>
    X("misra-module", "Adds MISRA C++ 2023 checks.");
} // namespace misra

// This anchor is used to force the linker to link in the generated object file
// and thus register the ZirconModule.
volatile int MisraModuleAnchorSource = 0;

} // namespace clang::tidy
