# Playdate C Project Template

A template for pure C games (just as the founding fathers intended) for the [Playdate handheld console](https://play.date). This is intended to be used with `make` or `nix develop -c make` to automatically build with the arm compiler and playdate SDK installed through Nix. As with all playdate projects, make sure you have the playdate SDK path in your environment variables (guide available in the official [Inside Playdate with C](https://sdk.play.date/2.4.2/Inside%20Playdate%20with%20C.html#_set_playdate_sdk_path_environment_variable) document).

This template automatically grabs all the c files in the src directory (and all sub-directories) so you dont have to manually add them to the Makefile. The setup stuff used by all playdate c projects is kept in `main.c`, so you can focus on making your game in `game.c` and any included module files.

I used this as the template for my own games, which you can find on my [itch.io](https://renpenguin.itch.io)
