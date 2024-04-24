# **ZMQ_DND-DiceApp**
**“Roll-a-dice” Service voor Dungeons & Dragons (DnD)**

## **Overzicht:**
Dit programma fungeert als een eenvoudige dienst om willekeurige getallen te genereren voor Dungeons & Dragons (DnD)-spellen. Het luistert naar inkomende verzoeken voor dobbelsteenworpen en antwoordt met een willekeurig getal binnen het opgegeven bereik.

## **Topologie**

![DND Roll a dice topologie](https://github.com/Sicatriz/ZMQ_DND-DiceApp/blob/main/img/diagram_DND.png)

## **Afhankelijkheden:**
- `iostream`: Bibliotheek voor invoer/uitvoer voor de console.
- `string`: Standaard stringbibliotheek voor het manipuleren van strings.
- `zmq.hpp`: ZeroMQ-bibliotheek voor berichtenverkeer.
- `QString`: Qt-bibliotheek voor het manipuleren van strings.
- `windows.h` (Windows): Headerbestanden voor de slaapfunctie.
- `SLEEP(n)`: Macro voor de slaapfunctie (alleen Windows).

## **Functionaliteit:**
1. **Opzetten van ZeroMQ-context en -sockets:**
   - Het programma stelt een ZeroMQ-context in met een enkele I/O-thread.
   - Er worden twee ZeroMQ-sockets gemaakt:
     - `ventilator`: Een PUSH-socket die wordt gebruikt om berichten te verzenden.
     - `subscriber`: Een SUB-socket die wordt gebruikt om berichten te ontvangen.

2. **Verbinding maken met ZeroMQ-kanalen:**
   - De socket `ventilator` is verbonden met een PUSH-kanaal op het adres `"tcp://benternet.pxl-ea-ict.be:24041"`.
   - De socket `subscriber` is verbonden met een SUB-kanaal op het adres `"tcp://benternet.pxl-ea-ict.be:24042"`. Het abonneert zich op berichten die beginnen met het voorvoegsel `"DnD?>Dice>[gevraagde dobbelste(e)n(en)]>[UserID]>"`.

3. **Ontvangen en Verwerken van Berichten:**
   - Het programma wacht op een bericht op de socket `subscriber`.
   - Na ontvangst van een bericht wordt het omgezet naar een string en afgedrukt op de console.
   - De string wordt vervolgens omgezet naar een `QString` voor verdere verwerking.

4. **Genereren van Willekeurige Getallen:**
   - Als het ontvangen bericht een DnD-stijl dobbelsteenworpverzoek (`"DnD?>Dice>"`) is, genereert het programma een willekeurig getal binnen het bereik dat is gespecificeerd in het verzoek.
   - Het stuurt het resultaat terug via de socket `ventilator` als een antwoordbericht.

5. **Uitzonderingsafhandeling:**
   - Eventuele uitzonderingen die zich voordoen tijdens de uitvoering (bijvoorbeeld ZeroMQ-fouten) worden opgevangen, en er wordt een foutmelding afgedrukt op de console.

## **Gebruik:**
- Zorg ervoor dat de ZeroMQ-bibliotheek is geïnstalleerd en correct is geconfigureerd.
- Compileer en voer het programma uit.
- Maak verbinding met de gespecificeerde kanalen om DnD-dobbelsteenworpverzoeken te verzenden en willekeurige getallen te ontvangen.
- De bepaling van de dobbelrange wordt bepaald door het getal van toe te voegen van de gevraagde dobbelsteen.  Bv 4, 6, 8, 10, 12 of 20.  Het aantal gegooide dobbelstenen wordt bepaald door de waarde voor de D.  Bijvoorbeel 1D6 resulteerd in 1 dobbelsteen met een waarde tussen 1 en 6.

Example:

- Client doet een request met "DnD?>Dice>1D6>LordAres>" en krijgt 1 waarde tussen 1 en 6 terug (bv 5) van de service in de vorm "DnD?>Dice>1D6>LordAres>5>"
- Client doet een request met "DnD?>Dice>2D20>LordAres>" en krijgt 2 waarden tussen 1 en 20 terug (bv 8 en 17) van de service in de vorm "DnD?>Dice>1D6>LordAres>8_17>"


## **Opmerkingen:**
- Dit programma gaat uit van een specifiek berichtformaat voor DnD-dobbelsteenworpverzoeken en -antwoorden.
- Foutafhandeling voor ongeldige invoer of onverwachte berichten is niet geïmplementeerd in deze versie.

