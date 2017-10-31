.PHONY: all clean flex compile
all: flex compile

flex:
	@ flex -d -o scanner.lex.c -l scanner.l   

compile: 
	@ gcc -o $(ROOT_DIR)/decaf -ldl scanner.lex.c $(ROOT_DIR)/$(PARSER)/parser.tab.c
	
clean: 
	@rm -f scanner.lex.c $(ROOT_DIR)/decaf
