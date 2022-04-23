# boitapotard-midi
Teensy LC + 8 potards rotatifs linéaires 10kΩ + librairie [MIDIController](https://github.com/joshnishikawa/MIDIcontroller)

Utilise intensément la formidable librairie de John Nishikawa [MIDIController](https://github.com/joshnishikawa/MIDIcontroller) qui permet de gérer boutons, potards, encodeurs, pour créer des contrôleurs midi.

```
 teensy LC | --- | Control num
------------------------------------
     14/A0 | --- | 51  
     15/A1 | --- | 52
     16/A2 | --- | 53
     17/A3 | --- | 54
     18/A4 | --- | 55
     19/A5 | --- | 56
     20/A6 | --- | 57
     21/A7 | --- | 58
     
```
**Teensy LC :** 
- pas cher (<20€)
- possibilités MIDI
- 8 entrées analogiques
- de la RAM
- une led intégrée

Dans Processing, j'utilise cette autre formidable librairie [theMidiBus](https://github.com/sparks/themidibus) de Severin Smith, pour intercepter les messages midi.
