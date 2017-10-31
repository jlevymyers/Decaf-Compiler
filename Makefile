.PHONY: all clean all_scanner all_parser clean_scanner clean_parser

CC	= gcc
CFLAGS 	= -Wextra -Werror

ROOT_DIR=$(PWD)
SCANNER:=scanner/
PARSER:=parser/

export CC CFLAGS ROOT_DIR SCANNER PARSER


all: all_parser all_scanner

all_scanner: 
	@ cd $(ROOT_DIR)/$(SCANNER) && $(MAKE) all

all_parser: 
	@cd $(ROOT_DIR)/$(PARSER) && $(MAKE) all

clean: clean_scanner clean_parser

clean_scanner:
	@cd $(SCANNER) && $(MAKE) clean

clean_parser:
	@cd $(PARSER) && $(MAKE) clean

