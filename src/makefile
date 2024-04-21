# The project name
export PROJECTNAME = AESCrypt
SOURCE_DIR = .
HEADERS_DIR = ../inc
BUILD_DIR  = ../objects
RESULT_DIR = ../result

SOURCE += main.c
SOURCE += cryption.c
SOURCE += usermessages.c

INCLUDE += -I$(SOURCE_DIR) 
INCLUDE += -I$(HEADERS_DIR)

CFLAGS += -std=c11 -Wall -Wextra -Wno-unused-variable

CC	= gcc

LIBS += -lgcrypt

all: $(PROJECTNAME)

# The object files
OBJS := $(foreach ofile,$(SOURCE),$(BUILD_DIR)/$(notdir $(patsubst %.cpp,%.o,$(ofile:%.c=%.o))))

define template_cfile
$(BUILD_DIR)/$$(notdir $(patsubst %.cpp,%.o,$(1:%.c=%.o))): $(1)
	@echo Compile $(1) ...
	@$$(CC) $$(CFLAGS) -c $$< -o $$@ $$(LIBS) $$(INCLUDE)
endef

$(foreach cfile,$(SOURCE),$(eval $(call template_cfile,$(cfile))))

$(BUILD_DIR):
	@mkdir $(BUILD_DIR)

$(RESULT_DIR):
	@mkdir $(RESULT_DIR)

$(RESULT_DIR)/$(PROJECTNAME): $(OBJS)
	@echo Create $(PROJECTNAME) ...
	@$(CC) $(OBJS) -o  $(RESULT_DIR)/$(PROJECTNAME) $(LDFLAGS) $(LIBS)

$(PROJECTNAME): $(BUILD_DIR) $(RESULT_DIR) $(RESULT_DIR)/$(PROJECTNAME)

run: $(PROJECTNAME)
	@echo Run ...
	@$(RESULT_DIR)/$(PROJECTNAME)

clean: $(CLEAN_MODS)
	@echo Clean ...
	@$(RM) -r $(BUILD_DIR)
	@$(RM) -r $(RESULT_DIR)
	@echo Ok.


