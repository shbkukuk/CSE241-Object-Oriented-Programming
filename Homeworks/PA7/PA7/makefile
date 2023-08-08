
JC = javac
JFLAGS = -g
JVM = java
MAIN = Test
SRCDIR = src
BINDIR = bin


default: run
compile:
	$(JC) $(JFLAGS) -sourcepath $(SRCDIR) -d $(BINDIR) $(SRCDIR)/*.java

run: compile
	$(JVM) -cp $(BINDIR) $(MAIN)

clean:
	$(RM) -r $(BINDIR)