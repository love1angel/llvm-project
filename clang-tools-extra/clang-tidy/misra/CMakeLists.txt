set(LLVM_LINK_COMPONENTS
  FrontendOpenMP
  Support
  )

add_clang_library(clangTidyMisraModule STATIC
  ArrayDeclarationCheck.cpp
  MisraTidyModule.cpp

  LINK_LIBS
  clangTidy
  clangTidyUtils

  DEPENDS
  omp_gen
  ClangDriverOptions
  )

clang_target_link_libraries(clangTidyMisraModule
  PRIVATE
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  )
