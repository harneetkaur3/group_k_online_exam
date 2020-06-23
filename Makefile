# ------------------------------------------------
# Generic Makefile
#
# @author Harneet Kaur - harneetkaur3@cmail.carleton.ca
# @author 
# @author 
# @author 
# 

# Date  : 2020-06-21
#
# Changelog :
# 2020-06-21: Inital Draft
# 2020-06-21: Makefile
#
# ------------------------------------------------

# ExamOnline (generate executable with this name)

TARGET   = Examonline

# change these to proper directories where each file should be


SRCDIR     	 = src
SRCTESTDIR	 = test
OBJDIR    	 = obj
BINDIR    	 = bin
INCDIR	  	 = include

CC       = gcc
INC      := -I$(INCDIR)
#starting of compilation of all source files...........

Examonline:

	$(CC) -g -O -c $(SRCDIR)/main.c -fPIC -DPIC -o $(OBJDIR)/main.o
	
	$(CC) -g -O -c $(SRCDIR)/user_maintainance.c -fPIC -DPIC -o $(OBJDIR)/user_maintainance.o
	
	$(CC) -g -O -c $(SRCDIR)/validation.c -fPIC -DPIC -o $(OBJDIR)/validation.o
	
	$(CC) -g -O -c $(SRCDIR)/student.c -fPIC -DPIC -o $(OBJDIR)/student.o
	
	$(CC) -g -O -c $(SRCDIR)/professor.c -fPIC -DPIC -o $(OBJDIR)/professor.o
	
	$(CC) -g -O -c $(SRCDIR)/profile_creation.c -fPIC -DPIC -o $(OBJDIR)/profile_creation.o
	
	$(CC) -g -O -c $(SRCDIR)/exam.c -fPIC -DPIC -o $(OBJDIR)/exam.o
	
	$(CC) -g -O -c $(SRCTESTDIR)/test.c -fPIC -DPIC -o $(OBJDIR)/objtest/test.o
	
	$(CC) -o $(BINDIR)/$(TARGET) $(OBJDIR)/*.o 
	
	$(CC) -o $(BINDIR)/Test $(OBJDIR)/objtest/test.o obj/user_maintainance.o obj/validation.o obj/student.o obj/professor.o obj/profile_creation.o obj/exam.o
	
	@echo "Now you can run test and Examonline files from  bin directory by using following commands"
	@echo "bin/./Examonline"
	@echo "bin/./test"
	
.PHONY: clean
clean:
	@$(rm) $(BINDIR)/$(TARGET)
	@$(rm) examonline.txt
	@echo "Cleanup complete!"
	
