SRCS = final.c
TARG = final
CC = gcc
OPTS = -Wall -O
all: $(TARG)

$(TARG): $(SRCS)
		   $(CC) -o $(TARG) $(STCS)

%.o: %.c
		$(CC) $(OPTS) -c $< -o $@

clean:
		rm -f $(TARG)
