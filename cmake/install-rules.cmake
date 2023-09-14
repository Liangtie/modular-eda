install(
    TARGETS modular-eda_exe
    RUNTIME COMPONENT modular-eda_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
