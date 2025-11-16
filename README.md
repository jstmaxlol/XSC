# xsc3🧮
**xsc3** (e**X**tremely**S**imple**C**alculator **3**): the aaaaa-iest way to calculate stuff in the terminal \
syntax: `xsc <num1> <(+|-|x|/|%|^)> <num2>` or `xsc r <num>` \
pros: supports floating point number operations.. or smth \
**note**: compile with **g++**

## AUR⭐
**xsc3** is now available on the [Arch User Repository](https://aur.archlinux.org/packages/xsc), \
install it with your favourite AUR helper:
* `yay` : `yay -S xsc`
* `paru` : `paru -S xsc`
* `trizen` : `trizen -S xsc`
* `pamac` : `pamac build xsc`
* `aurman` : `aurman -S xsc`

## dependencies🤓
* `figlet` : `paru -S figlet`
* `lolcat` : `paru -S lolcat`

## manual installation one-liner🤖
#### downloads dependencies, clones repo and compiles **xsc3** ;
`paru -S figlet lolcat gcc && git clone https://github.com/jstmaxlol/xsc && cd ./xsc && g++ -o xsc xsc.cpp -O2 -std=c++23`
#### (optional, but recommended for actually using xsc) moves **xsc3** to PATH ;
`mv ./xsc /usr/bin/xsc` \
if didn't know, adding a binary to PATH makes it so that you do not have to find yourself in the installation path of the binary to execute it!

## usage⭐
uhh.. `xsc h` and stfu

&nbsp;
###### jstmax! : <jstmaxlol@disroot.org>, <maxwasmailed@proton.me>
