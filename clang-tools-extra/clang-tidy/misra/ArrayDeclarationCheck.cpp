//===--- ArrayDeclarationCheck.cpp - clang-tidy ---------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "ArrayDeclarationCheck.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang::tidy::misra {

void ArrayDeclarationCheck::registerMatchers(MatchFinder *Finder) {
  Finder->addMatcher(varDecl(hasType(incompleteArrayType()),
                             hasExternalFormalLinkage(),
                             unless(hasInitializer(anything())))
                         .bind("unsizedArray"),
                     this);
}

void ArrayDeclarationCheck::check(const MatchFinder::MatchResult &Result) {
  const auto *Var = Result.Nodes.getNodeAs<VarDecl>("unsizedArray");
  if (!Var)
    return;
  if (!Var->hasExternalFormalLinkage())
    return;
  diag(Var->getLocation(), "array: %0 's size is not specificed.")
      << Var->getName();
}

} // namespace clang::tidy::misra
