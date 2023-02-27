all: menubar
hello: hello.c
	gcc -W -Wall -Werror -Wextra -I./Includes/.  hello.c -std=c99 -lncurses -o hello
window: window.c
	gcc -W -Wall -Werror -Wextra -I./Includes/.  window.c -std=c99 -lncurses -o window
colour: colour.c
	gcc -W -Wall -Werror -Wextra -I./Includes/.  colour.c -std=c99 -lncurses -o colour
io: io.c
	gcc -W -Wall -Werror -Wextra -I./Includes/.  io.c -std=c99 -lncurses -o io
halfdelay: halfdelay.c
	gcc -W -Wall -Werror -Wextra -I./Includes/.  halfdelay.c -std=c99 -lncurses -o halfdelay
dedect: dedect.c
	gcc -g -W -Wall -Werror -Wextra -I./Includes/.  dedect.c -std=c99 -lncurses -o dedect
menubar: menubar.c
	gcc -g -W -Wall -Werror -Wextra -I./Includes/. menubar.c  -std=c99 -lncurses -o menubar
