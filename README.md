# BB_BIKE

## Probem

I current do not have any safety lighting for my bike. there for going for a early morning and late night ride is currently out of the question.

## Goal

The goal is to use a ESP8266 NodeMCU to control a lighting + safety system. I intend to enable lighting, basic and otherwise.
1. The headlights and tail light should be enabled by default if system is on. ~~Every other tail light led should be off unless brakes are applied.~~ 
2. if brakes are engaged, all tail lights should be set to max brightness.

## TODO

1. find a way to toggle signal states
2. find proper power source
3. design layout and mounting

## details/ideas

i have mapped my first draft of th light layout. originally I wanted to use strips on the forks as headlights. theheadlights I hope to have as an addition to a handlebar mounted light. the markers I intend to mount facing out to the left and right, one set on the outside of forks and the second set on the outside of the frames center support.

using the ESP8266 NodeMCU i plan to use as few IO possible. I will alloow three states, low/on/high, much like a cars lighting options.
1. with the reqirement that the default lighting state is to have the headlights set to low and everyother tail light led set aswell.
2. after a few strokes, the lights should be set to on
3. the option to switch te lights to high should be a manually set be the rider. high sets an additional set of leds to high illuminating the bottom part of frame.


