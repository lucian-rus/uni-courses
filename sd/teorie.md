# Teorie pentru examen — Structuri de date

*Sinteză a teoriei pe capitolele din recapitulare: stive/cozi/liste, arbori binari, heap binar, tabele de dispersie, arbori binari de căutare, arbori echilibrați (AVL, ARN), B-arbori și biblioteca STL.*

**Convenție folosită peste tot:** înălțimea unui arbore = numărul de muchii pe cel mai lung drum de la rădăcină la o frunză (rădăcina are adâncimea/nivelul 0). Un nod singur are înălțimea 0.

---

## 1. Stive, cozi și liste înlănțuite

### Stiva (stack) — LIFO
Structură de tip **Last In, First Out**: ultimul element adăugat este primul scos. Operații: `push` (adaugă în vârf), `pop` (scoate din vârf), `top`/`peek` (citește vârful), `empty`.

Probleme tipice: evaluarea expresiilor (notație poloneză), verificarea parantezelor, parcurgerea iterativă a arborilor (DFS), funcția de „undo", gestionarea apelurilor de funcții (stiva de execuție).

### Coada (queue) — FIFO
Structură de tip **First In, First Out**: primul element adăugat este primul scos. Operații: `push`/`enqueue` (adaugă la coadă), `pop`/`dequeue` (scoate din față), `front`, `back`, `empty`.

Probleme tipice: parcurgerea pe niveluri a arborilor (BFS), planificarea task-urilor, buffere, simulări.

### Lista înlănțuită
Secvență de noduri legate prin pointeri. **Simplu înlănțuită**: fiecare nod are pointer spre următorul. **Dublu înlănțuită**: pointeri spre următorul și spre precedentul (permite parcurgere în ambele sensuri).

### Complexitatea operațiilor

| Operație | Listă înlănțuită | Vector (tablou dinamic) |
|---|---|---|
| Inserare la început | `O(1)` | `O(n)` |
| Inserare la sfârșit | `O(1)`* | `O(1)` amortizat |
| Ștergerea unui nod (cu pointer la el, dublu înlănțuită) | `O(1)` | `O(n)` |
| Acces la al `k`-lea element | `O(n)` | `O(1)` |
| Căutare după valoare | `O(n)` | `O(n)` |

*\*`O(1)` doar dacă se păstrează un pointer la coadă; altfel `O(n)`.*

Stivele și cozile se pot implementa eficient atât peste un **vector**, cât și peste o **listă înlănțuită**, deoarece toate operațiile lor de bază sunt `O(1)`.

### Containere STL asociate
- `std::stack` — adaptor; container implicit `std::deque`.
- `std::queue` — adaptor; container implicit `std::deque`.
- `std::list` — listă dublu înlănțuită; `std::forward_list` — listă simplu înlănțuită.
- `std::deque` — coadă cu două capete; inserare/ștergere `O(1)` la ambele capete și acces aleator `O(1)`.

---

## 2. Arbori și arbori binari

### Noțiuni de bază
- **Rădăcină**: nodul fără părinte.
- **Frunză (nod extern)**: nod fără copii.
- **Nod intern**: nod cu cel puțin un copil.
- **Adâncimea unui nod**: numărul de muchii de la rădăcină la el.
- **Înălțimea unui nod**: numărul de muchii pe cel mai lung drum spre o frunză.
- **Relații**: părinte, fiu, frate (noduri cu același părinte).

Un **arbore binar** are fiecare nod cu cel mult 2 copii (stâng și drept). Un arbore binar **strict (full)** are fiecare nod intern cu exact 2 copii. Un arbore binar **complet** are toate nivelurile pline, cu excepția eventual a ultimului, completat de la stânga la dreapta.

### Formule de numărare (arbore binar de înălțime `h`)
- Număr maxim de noduri pe nivelul `d`: **`2^d`**.
- Număr maxim de noduri în tot arborele: **`2^(h+1) − 1`**.
- Număr minim de noduri (un „lanț"): **`h + 1`**.
- Înălțime **minimă** pentru `n` noduri: **`⌊log₂ n⌋`**.
- Înălțime **maximă** pentru `n` noduri: **`n − 1`** (arbore degenerat).
- Relația frunze / noduri cu 2 copii: **`n₀ = n₂ + 1`**.

### Parcurgeri
- **Preordine (RSD)**: Rădăcină → Stânga → Dreapta.
- **Inordine (SRD)**: Stânga → Rădăcină → Dreapta.
- **Postordine (SDR)**: Stânga → Dreapta → Rădăcină.
- **Pe niveluri (BFS)**: nivel cu nivel, de la stânga la dreapta (folosește o coadă).

Observații utile: în preordine, **primul** nod este rădăcina; în postordine, **ultimul** nod este rădăcina. Un arbore binar se poate reconstrui unic din **preordine + inordine** (sau postordine + inordine).

### Exemplu de parcurgeri
Pentru arborele:
```
        A
       / \
      B   C
     / \   \
    D   E   F
```
- Preordine (RSD): `A B D E C F`
- Inordine (SRD): `D B E A C F`
- Postordine (SDR): `D E B F C A`
- Pe niveluri (BFS): `A B C D E F`

---

## 3. Heap binar (max / min)

### Definiție
Un heap este un **arbore binar complet** memorat de regulă într-un **vector**. Proprietatea de heap:
- **Heap-max**: valoarea fiecărui părinte `≥` valorile copiilor → maximul este în rădăcină.
- **Heap-min**: valoarea fiecărui părinte `≤` valorile copiilor → minimul este în rădăcină.

### Indexare în vector
Indexare de la **1**: părinte(`i`) = `⌊i/2⌋`, copil stâng = `2i`, copil drept = `2i+1`.
Indexare de la **0**: părinte(`i`) = `⌊(i−1)/2⌋`, copil stâng = `2i+1`, copil drept = `2i+2`.

Pentru `n` elemente: nodurile interne sunt primele `⌊n/2⌋`, iar frunzele sunt ultimele `⌈n/2⌉`.

### Formule
- Număr de noduri într-un heap de înălțime `h`: între **`2^h`** (minim) și **`2^(h+1) − 1`** (maxim).
- Înălțimea unui heap cu `n` noduri: **`⌊log₂ n⌋`**.

### Operații și algoritmi
- **Inserare**: pui elementul pe ultima poziție, apoi îl ridici (*sift-up* / *percolate-up*) cât timp încalcă proprietatea. → `O(log n)`.
- **Extragerea maximului (heap-max) / minimului (heap-min)**: scoți rădăcina, muți ultimul element în rădăcină, apoi îl cobori (*sift-down* / *heapify*). → `O(log n)`.
- **Construirea heap-ului (build-heap)**: aplici *sift-down* de la ultimul nod intern (`⌊n/2⌋` sau `⌊n/2⌋−1` la indexare de la 0) spre rădăcină. → **`O(n)`** (nu `O(n log n)`!).
- **Citirea maximului/minimului** (vârful): `O(1)`.
- **Căutarea unei valori oarecare**: `O(n)` — heap-ul nu este eficient pentru căutarea după cheie.
- **Aflarea maximului într-un heap-min**: maximul este printre frunze → trebuie verificate toate frunzele → `O(n)`.

### Exemplu
Heap-max cu 7 elemente, memorat ca vector `[16, 14, 10, 8, 7, 9, 3]` (indexare de la 1):
```
        16
       /  \
     14    10
    /  \   / \
   8    7 9   3
```
Maximul (16) este în rădăcină. Frunzele sunt ultimele `⌈7/2⌉ = 4` elemente (8, 7, 9, 3). La inserarea cheii 20, aceasta se adaugă pe poziția 8 (sub 8) și urcă prin *sift-up* peste 8, 14, 16, devenind noua rădăcină.

### Container STL asociat
`std::priority_queue` — implicit **heap-max** peste `std::vector`. Cu `std::greater<>` devine heap-min. `push` și `pop` în `O(log n)`, `top` în `O(1)`.

---

## 4. Tabele de dispersie (hash)

### Idee și coliziuni
O funcție de dispersie `h(k)` mapează o cheie `k` la o poziție din tabelă (`0 … m−1`). Metoda diviziunii: `h(k) = k mod m`. O **coliziune** apare când două chei diferite primesc aceeași poziție.

### Factorul de încărcare
**`α = n / m`** (număr de chei / dimensiunea tabelei).

### Rezolvarea coliziunilor

**(a) Înlănțuire (chaining):** fiecare poziție conține o listă înlănțuită cu toate cheile care se dispersează acolo.
- `α` poate fi `> 1`.
- Căutare medie (dispersie uniformă): `O(1 + α)`; în cazul cel mai defavorabil `O(n)`.

**(b) Adresare deschisă:** cheile se stochează direct în tabelă; la coliziune se sondează alte poziții.
- `α ≤ 1` (cel mult `m` chei).
- **Dublă repartizare**: poziția la sonda `i` este `(h1(k) + i·h2(k)) mod m`. Pentru ca secvența de sondare să poată atinge **toate** pozițiile, `h2(k)` trebuie să fie **prim relativ cu `m`** pentru orice `k` (și niciodată 0). Alegeri uzuale: `m` prim cu `h2(k) = 1 + k mod (m−1)`, sau `m` putere a lui 2 cu `h2` întorcând doar valori impare.

### Complexitatea operațiilor
Sub ipoteza dispersiei uniforme: inserare, căutare și ștergere în **`O(1)` în medie (amortizat)**; în cazul cel mai defavorabil **`O(n)`**.

### Containere STL asociate
- `std::unordered_map`, `std::unordered_set` — bazate pe hash-table: `O(1)` în medie, **fără** ordine garantată a cheilor.
- (Spre comparație) `std::map`, `std::set` — bazate pe arbore echilibrat: `O(log n)`, **cu** chei sortate.

---

## 5. Arbori binari de căutare (ABC)

### Proprietate
Pentru orice nod `x`: toate cheile din subarborele **stâng** sunt `<` cheia lui `x`, iar toate cheile din subarborele **drept** sunt `>` cheia lui `x`.

Consecință importantă: **parcurgerea în inordine (SRD) produce cheile în ordine crescătoare.**

### Operații
- **Căutare**: cobori la stânga/dreapta comparând cu cheia curentă. `O(h)`.
- **Inserție**: cauți poziția și adaugi noul nod ca frunză. `O(h)`.
- **Ștergere** (3 cazuri):
  1. nod frunză → se șterge direct;
  2. nod cu un singur copil → se înlocuiește cu copilul;
  3. nod cu doi copii → se înlocuiește cu **succesorul în inordine** (minimul subarborelui drept) sau cu predecesorul (maximul subarborelui stâng), apoi se șterge acel nod.
- **Succesor** al unui nod: dacă are subarbore drept, este minimul acestuia; altfel, cel mai apropiat strămoș al cărui subarbore stâng îl conține pe nod.
- **Predecesor**: simetric (subarbore stâng / maxim).

### Exemplu
Arbore binar de căutare:
```
        15
       /  \
      6    18
     / \   / \
    3   7 17  20
```
Inordine: `3 6 7 15 17 18 20` (crescător). Succesorul lui 15 este **17** (minimul subarborelui drept); predecesorul lui 15 este **7** (maximul subarborelui stâng). Ștergerea cheii 6 (are doi copii) → se înlocuiește cu succesorul ei, 7:
```
        15
       /  \
      7    18
     /     / \
    3     17  20
```

### Complexitate
Toate operațiile sunt `O(h)`. Dacă arborele este **echilibrat**, `h = O(log n)`; în cazul cel mai defavorabil (arbore degenerat, inserții sortate), `h = n − 1` și operațiile devin `O(n)`. De aici nevoia de arbori echilibrați.

---

## 6. Arbori binari de căutare echilibrați

### Rotații
Operația de bază pentru reechilibrare. **Rotația păstrează proprietatea de ABC** (parcurgerea în inordine rămâne neschimbată). Există rotație stânga și rotație dreapta.

### Arbori AVL
Arbore binar de căutare în care, pentru fiecare nod, **factorul de balansare** (înălțimea subarborelui stâng minus a celui drept) aparține mulțimii **`{−1, 0, +1}`**.

**Reechilibrare după inserție/ștergere** — 4 cazuri:

| Caz | Situație | Rotație |
|---|---|---|
| Stânga-Stânga (LL) | greu pe stânga, fiul stâng greu pe stânga | o rotație **dreapta** |
| Dreapta-Dreapta (RR) | greu pe dreapta, fiul drept greu pe dreapta | o rotație **stânga** |
| Stânga-Dreapta (LR) | greu pe stânga, fiul stâng greu pe dreapta | stânga la fiu, apoi dreapta la nod |
| Dreapta-Stânga (RL) | greu pe dreapta, fiul drept greu pe stânga | dreapta la fiu, apoi stânga la nod |

**Exemple de rotații:**

Caz LL — o rotație dreapta în 30:
```
    30                 20
   /                  /  \
  20        →       10    30
 /
10
```
Caz RR — o rotație stânga în 10:
```
  10                   20
    \                 /  \
     20      →      10    30
       \
        30
```
Caz LR — rotație stânga în 10, apoi dreapta în 30:
```
    30           30              20
   /            /               /  \
  10     →     20      →      10    30
    \         /
     20      10
```
Caz RL — rotație dreapta în 30, apoi stânga în 10:
```
  10            10                20
    \             \              /  \
     30    →       20     →    10    30
    /                \
   20                 30
```

Număr minim de noduri al unui AVL de înălțime `h`: **`N(h) = 1 + N(h−1) + N(h−2)`**, cu `N(0) = 1`, `N(1) = 2` (creștere de tip Fibonacci). De aici, înălțimea unui AVL este `O(log n)`, deci toate operațiile sunt **`O(log n)`** în cazul cel mai defavorabil.

### Arbori roșu-negru (ARN)
Arbore binar de căutare cu următoarele **proprietăți**:
1. Fiecare nod este **roșu** sau **negru**.
2. Rădăcina este **neagră**.
3. Fiecare frunză (`NIL`) este **neagră**.
4. Un nod roșu are ambii copii **negri** (nu există două noduri roșii consecutive).
5. Pentru fiecare nod, **toate** drumurile spre frunzele descendente conțin **același număr de noduri negre**.

**Înălțimea neagră `bh`** = numărul de noduri negre pe orice drum de la un nod (sau de la rădăcină) la o frunză `NIL`, incluzând `NIL`.

Formule (în funcție de `bh`):
- Număr **minim** de noduri: **`2^bh − 1`** (arbore complet negru).
- Număr **maxim** de noduri: **`2^(2·bh) − 1`** (arbore care alternează negru-roșu).
- În arborele maxim: noduri negre = `(4^bh − 1)/3`, noduri roșii = `2·(4^bh − 1)/3`.
- Pe orice drum, numărul de noduri roșii este `≤ bh`, deci drumul cel mai lung este cel mult dublul celui mai scurt.
- Înălțimea unui ARN cu `n` noduri: `≤ 2·log₂(n + 1)` → `O(log n)`.

### Exemplu
Arbore roșu-negru valid (N = negru, R = roșu), cu înălțimea neagră `bh = 2`:
```
            20(N)
          /       \
       10(N)       30(N)
      /    \       /    \
    5(R)  15(R)  25(R)  35(R)
```
Verificare: rădăcina e neagră; nodurile roșii (5, 15, 25, 35) au copii negri (`NIL`); pe fiecare drum rădăcină→`NIL` se găsesc 2 noduri negre. Pentru `bh = 2`: minimul ar fi `2² − 1 = 3` noduri, maximul `2⁴ − 1 = 15`; acest arbore are 7 noduri.

**Inserția**: noul nod se colorează **roșu**; dacă apare un conflict roșu-roșu cu părintele, se aplică reparații în funcție de culoarea **unchiului**:
- unchi **roșu** → **recolorare** (părinte și unchi devin negre, bunicul roșu) și se urcă în arbore;
- unchi **negru** → **rotație** (+ recolorare), în mod analog cazurilor AVL (linie → o rotație; „triunghi" → două rotații).

### Containere STL bazate pe arbori echilibrați
`std::map`, `std::set`, `std::multimap`, `std::multiset` — implementate tipic cu **arbori roșu-negru**: chei sortate, operații `O(log n)`.

---

## 7. B-arbori

### Proprietăți (grad minim `t ≥ 2`)
- Fiecare nod (cu excepția rădăcinii) are între **`t − 1`** și **`2t − 1`** chei.
- Rădăcina are cel puțin 1 cheie (dacă arborele nu e vid).
- Un nod intern cu `j` chei are exact `j + 1` copii; deci între `t` și `2t` copii.
- Cheile dintr-un nod sunt **sortate**, iar copiii separă intervalele de chei (generalizare a ABC).
- **Toate frunzele se află pe același nivel** (arbore perfect echilibrat în înălțime).

### Formule (grad minim `t`, înălțime `h`, `n` chei)
- Număr **minim** de chei: **`2·tʰ − 1`** (rădăcina cu 1 cheie, restul cu `t − 1`).
- Număr **maxim** de chei: **`(2t)^(h+1) − 1`** (toate nodurile pline).
- Din limita minimă rezultă înălțimea maximă: **`h ≤ log_t((n + 1)/2)`**.
- Înălțimea minimă (toate nodurile pline): **`h ≥ log_(2t)(n + 1) − 1`**.

### Inserție
Se caută frunza potrivită; dacă un nod este plin (`2t − 1` chei), se **divizează (split)**: mediana urcă în părinte, restul cheilor se împart în două noduri. Dacă se umple și rădăcina, aceasta se divizează și **înălțimea arborelui crește cu 1**.

### Exemplu
B-arbore cu grad minim `t = 2` (maxim 3 chei pe nod), de înălțime 1:
```
        [ 10 , 20 ]
       /     |      \
   [5 8]  [12 15]  [25 30]
```
Cheile din rădăcină separă intervalele: copilul stâng conține chei `< 10`, cel din mijloc între 10 și 20, iar cel drept `> 20`. Dacă s-ar insera o a 4-a cheie într-un nod plin (3 chei), nodul s-ar diviza, iar mediana ar urca în părinte.

### Complexitate
Căutarea, inserția și ștergerea sunt **`O(log n)`** (mai exact `O(t · log_t n)`). B-arborii sunt optimizați pentru stocarea pe disc, unde fiecare nod = un bloc de date.

---

## 8. Biblioteca STL — sinteză

### Tabel comparativ de complexitate

| Container | Structura de bază | Acces | Inserare | Căutare | Ordine |
|---|---|---|---|---|---|
| `vector` | tablou dinamic | `O(1)` (index) | `O(1)`* la final | `O(n)` | inserare |
| `deque` | blocuri | `O(1)` (index) | `O(1)` la capete | `O(n)` | inserare |
| `list` | dublu înlănțuită | `O(n)` | `O(1)` (cu iterator) | `O(n)` | inserare |
| `forward_list` | simplu înlănțuită | `O(n)` | `O(1)` (cu iterator) | `O(n)` | inserare |
| `stack` | adaptor (deque) | doar vârf | `O(1)` | — | LIFO |
| `queue` | adaptor (deque) | față/spate | `O(1)` | — | FIFO |
| `priority_queue` | heap (vector) | vârf `O(1)` | `O(log n)` | — | după prioritate |
| `set` / `map` | arbore roșu-negru | — | `O(log n)` | `O(log n)` | **sortată** |
| `unordered_set` / `unordered_map` | hash-table | — | `O(1)` mediu | `O(1)` mediu | **niciuna** |

*\*`O(1)` amortizat (poate apărea redimensionare).*

### Iteratori
- `m.begin()`, `m.end()` delimitează intervalul; `end()` este „după ultimul".
- `m.find(k)` întoarce un iterator la cheie sau `m.end()` dacă nu există.
- Pentru `map`/`set`: `it->first` = cheia, `it->second` = valoarea (la `map`).
- Iteratorii de `map`/`set`/`list` sunt **bidirecționali** (`++`, `--`), **nu** random access; cei de `vector`/`deque` sunt **random access** (`it + k`, `it < end`).
- Parcurgerea unui `map`/`set` dă cheile în ordine **crescătoare**; a unui `unordered_*` nu garantează nicio ordine.
- `operator[]` la `map`: dacă cheia nu există, o **inserează** cu valoarea implicit-construită (ex. `int → 0`).

### Ce structură, în ce situație
- **Coadă de priorități** → `priority_queue` (heap).
- **Căutare/inserare/ștergere `O(log n)` în cazul cel mai defavorabil, cu chei sortate** → `map`/`set` (ARN).
- **Căutare/inserare rapidă în medie, fără nevoie de ordine** → `unordered_map`/`unordered_set` (hash).
- **Acces aleator rapid prin index** → `vector` / `deque`.
- **Inserări/ștergeri frecvente în interior, cu iterator** → `list`.
- **LIFO / FIFO** → `stack` / `queue`.

---

## Anexă — formule cheie (recapitulare rapidă)

| Subiect | Formulă |
|---|---|
| Arbore binar, max noduri de înălțime `h` | `2^(h+1) − 1` |
| Arbore binar, max noduri pe nivelul `d` | `2^d` |
| Arbore binar, înălțime minimă pentru `n` noduri | `⌊log₂ n⌋` |
| Arbore binar, relația frunze/noduri cu 2 copii | `n₀ = n₂ + 1` |
| Heap, noduri de înălțime `h` | între `2^h` și `2^(h+1) − 1` |
| Heap, înălțime pentru `n` noduri | `⌊log₂ n⌋` |
| Heap, build-heap | `O(n)`; insert/extract `O(log n)` |
| Hash, factor de încărcare | `α = n/m` |
| Hash, sondă la dublă repartizare | `(h1(k) + i·h2(k)) mod m` |
| AVL, factor de balansare | `∈ {−1, 0, +1}` |
| AVL, noduri minime | `N(h) = 1 + N(h−1) + N(h−2)` |
| ARN, noduri pentru `bh` | între `2^bh − 1` și `2^(2·bh) − 1` |
| ARN, înălțime maximă | `≤ 2·log₂(n + 1)` |
| B-arbore, chei pentru `t`, `h` | între `2·tʰ − 1` și `(2t)^(h+1) − 1` |
| B-arbore, chei pe nod (≠ rădăcină) | între `t − 1` și `2t − 1` |