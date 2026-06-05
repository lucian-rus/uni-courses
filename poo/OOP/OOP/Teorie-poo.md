# Programare Orientata pe Obiecte — Teorie

## 0. Class vs Struct

Clasele reprezintă o extindere a structurilor de date. Acestea pot să conțină date, la fel ca structurile, dar în interiorul lor se pot afla și funcții. Noțiunea aceasta de funcții din interiorul unei structuri de date constituie diferența majoră dintre cele două modalități de reprezentare a datelor.

**Mențiune:** Aici vorbim de struct-ul din C standard. În C++, se pot adăuga funcții în interiorul unei structuri de date obișnuite și nu diferă atât de mult de o clasă.

---

## 1. Descrieți pe scurt în ce constă mecanismul de încapsulare

Mecanismul de încapsulare este procesul în care se creează un nou tip de date (abstract) definind o clasă ca fiind formată din câmpuri (structuri de date) și metode (funcții/algoritmi).

Fiecare câmp sau metodă are un atribut de acces:
- **private** — poate fi accesat doar de metodele clasei
- **protected** — poate fi accesat și de metodele claselor derivate
- **public** — poate fi accesat de oriunde din program

Dacă nu este pus un atribut de acces, atunci atributul de acces implicit va fi **private**.

**Exemplu de definire a unei clase:**

```cpp
class NumeClasa {
    [modificator_de_acces]:
        date;
        metode;
} [numeObiecte de tipul NumeClasa];
```

---

## 2. Obiectul implicit al unei metode

Obiectul implicit este obiectul care apelează metoda. În cadrul metodei, câmpurile obiectului implicit nu vor mai avea specificat cărui obiect aparțin, subînțelegându-se că ele aparțin obiectului implicit (adică a celui care o apelează).

Obiectul implicit al unei metode se poate accesa și cu ajutorul pointerului `*this`:
- `this->a;` (pentru variabile)
- `this->f();` (pentru metode)

Este transmis în metodă prin referință (referință constantă dacă metoda este constantă).

---

## 3. Moștenirea virtuală și scopul în care este folosită

Moștenirea virtuală este o metodă de implementare a polimorfismului de execuție. Moștenirea virtuală este necesară atunci când avem 2 clase derivate dintr-o clasă de bază iar o a patra clasă derivată din cele două. Se folosește derivarea virtuală pentru a evita o problemă de ambiguizare (**problema diamantului**).

---

## 4. Proprietățile unui câmp constant al unei clase

Un câmp constant al unei clase este un câmp a cărei valoare nu se poate modifica. El se poate inițializa doar în lista de inițializare a constructorului și nicăieri în altă parte. Pentru a implementa un câmp constant, se adaugă înainte tipului de date cuvântul cheie `const`. De asemenea, dacă acest câmp constant este un obiect, el nu poate apela metode neconstante.

---

## 5. Mecanismul de tratare a excepțiilor

Sunt folosite cuvintele cheie `try`, `throw` și `catch`. Se implementează în felul următor:
- Semnalizarea apariției unei excepții prin intermediul unei valori care reprezintă excepția respectivă
- Recepționarea valorii prin care este semnalizată excepția
- Tratarea (rezolvarea) excepției semnalizate și recepționate

**În C++ se reprezintă astfel:**

```cpp
try {
    // instructiuni care se executa pana la posibila aparitie a exceptiei
    if (test) throw valoare;
    // instructiuni care se executa daca nu survine exceptia
}
catch (tip valoarea) {
    // instructiuni pentru tratarea / rezolvarea exceptiei
}
```

Dacă aruncăm o valoare de un anumit tip și nu există un `catch` care să prindă valori de acel tip, atunci vom avea eroare de execuție (`"Unhandled exception"`). Există de asemenea și posibilitatea de a pune `catch(...)` (fără tip) care prinde orice tip de valoare.

---

## 6. Diferența dintre un pointer și o referință

**Referința** este practic un pointer constant care se dereferențiază automat (un alias pentru un obiect care, odată atribuită unui obiect, nu se mai schimbă). Prin modificarea referinței se modifică și obiectul în sine.

**Pointerul** "pointează" (arată) către un obiect, dar obiectul spre care pointează poate fi schimbat. În schimb, pointerul când este declarat de un anumit tip nu mai poate pointa către un tip diferit.

---

## 7. Funcțiile virtuale și scopul în care sunt folosite

O funcție virtuală este o funcție care este declarată ca fiind `virtual` în clasa de bază și **redefinită** de o clasă derivată. Pentru a declara o funcție ca fiind virtuală, declararea sa este precedată de cuvântul cheie `virtual`. Redefinirea funcției în clasa derivată modifică și are prioritate față de definiția funcției din clasa de bază. Funcțiile virtuale reprezintă o metodă de implementare a polimorfismului de execuție.

O **funcție virtuală pură** este o funcție virtuală care nu are definiție în clasa de bază, deci trebuie definite în clasa derivată.

```cpp
// Functie virtuala pura:
virtual tip nume_functie(/*lista de parametri*/) = 0;

// Functie virtuala:
virtual tip nume_functie(/*lista de parametri*/);
```

O clasă care conține cel puțin o funcție virtuală pură se numește **abstractă** (și nu poate fi instanțiată).

---

## 8. Funcțiile statice (metodele statice)

Declararea unei funcții statice este precedată de cuvântul cheie `static`. O astfel de funcție are următoarele restricții:
- Ea poate să aibă acces doar la alți membri (câmpuri de date/funcții) de tip `static` ai clasei și bineînțeles la funcțiile și datele globale.
- Ele nu pot avea un pointer de tip `*this` (deci nu au obiect implicit).
- Nu poate exista o versiune static și una non-static ale aceleiași funcții.

Funcțiile statice pot fi folosite fără a mai declara un obiect, prin intermediul operatorului de rezoluție `::`, ele fiind independente de obiect. Funcțiile statice și câmpurile de date statice au fost create pentru a se păstra principiul încapsulării. Scopul funcțiilor statice este acela că pot "preinițializa" datele particulare de tip static, înainte de crearea efectivă a unui obiect.

---

## 9. Diferența dintre transferul prin valoare și prin referință constantă

**Transferul prin valoare** reprezintă copierea valorii transmise ca parametru actual în parametru formal, care este creat pe stivă la lansarea în execuție a funcției, ca o variabilă locală (automatică).

**Transferul prin referință constantă** evită consumul suplimentar de memorie pentru crearea unei alte variabile și ne asigură în același timp că variabila transmisă ca referință constantă nu va fi modificată.

**OBS.** Dacă transmitem obiecte prin apel prin referință, nu se mai creează noi obiecte temporare, ci se lucrează direct pe obiectul trimis ca referință (nu se mai apelează copy-constructorul și nici destructorul).

---

## 10. Cum se comportă destructorii la moștenire

Ordinea de execuție a destructorilor este **inversa** ordinii de execuție a constructorilor (adică de la clasele derivate spre clasa de bază). În cazul moștenirii multiple, ordinea de execuție a destructorilor este de la dreapta la stânga în lista de derivare.

---

## 11. Crearea dinamică de obiecte

Obiectele se pot crea dinamic folosind instrucțiunea `new` pentru alocarea memoriei în momentul execuției în heap. Constructorul inițializează zona de memorie alocată. Eliberarea memoriei alocată astfel se poate face cu ajutorul instrucțiunii `delete`. Când un obiect este creat dinamic, metodele și câmpurile de date se accesează cu ajutorul operatorului `->` și nu cu ajutorul operatorului `.`.

---

## 12. Proprietățile câmpurilor statice

- Câmpurile statice sunt comune tuturor obiectelor din clasă.
- Sunt independente de obiectele din clasă.
- Sunt create la lansarea programului.
- Funcțiile statice pot opera doar asupra variabilelor statice din clasă.
- Sunt declarate în interiorul clasei, dar trebuie declarate și global.
- În cadrul acestor funcții nu există pointerul `*this`, pentru că aceste metode se apelează indiferent dacă există sau nu obiecte instanțiate.
- Funcțiile statice nu pot avea natură virtuală.

**Sintaxa:**
```cpp
class A { static void numara(); };
```

**Exemplu de utilizare:** metodele statice sunt utilizate pentru accesarea datelor statice, care au fost declarate ca fiind private (principiul încapsulării).

---

## 13. Proprietățile destructorului

- Într-o clasă există un singur destructor.
- Există un destructor implicit, pe care îl putem suprascrie.
- În cazul moștenirii, ordinea de execuție a destructorilor este inversa ordinii de execuție a constructorilor (adică de la clasele derivate spre clasa de bază).
- Se declară astfel: `class A { ~A(); };`
- Destructorul se apelează automat în momentul ieșirii din blocul în care a fost declarat obiectul.

---

## 14. Transferul parametrilor prin pointeri vs prin referință

**Transferul prin pointeri** reprezintă copierea adresei transmise ca parametru actual în parametrul formal, care este creat pe stivă la lansarea în execuție a funcției ca variabilă locală, modificările asupra parametrilor fiind vizibile și în afara funcției.

**Transferul prin referință** reprezintă crearea unei referințe locale către variabila transmisă ca parametru actual la lansarea în execuție a funcției.

---

## 15. Mecanismul de control al tipului în timpul execuției (RTTI)

RTTI cuprinde operatorul `typeid` și operația `dynamic_cast<>`.

- **`typeid()`** — permite aflarea tipului obiectului (clasa din care face parte) la execuție atunci când ai doar un pointer sau o referință către acel tip.

  **Exemplu:**
  ```cpp
  int myint = 50;
  std::cout << typeid(myint).name();
  ```

- **`dynamic_cast<>`** — se poate aplica pe pointeri sau referință, realizează convertirea unui obiect de un anumit tip la alt tip.

  **Sintaxa:**
  ```cpp
  dynamic_cast<tipul_la_care_vrem_sa_convertim>(ceea_ce_vrem_sa_convertim)
  ```

---

## 16. Diferența dintre o clasă și un obiect

**Clasa** reprezintă un tip abstract de date, format din câmpuri de date (structuri de date) și metode (funcții/algoritmi).

**Obiectul** este o instanță a unei clase.

Atunci când o clasă este creată, nu se alocă memorie, pe când atunci când un obiect este creat se alocă memorie.

---

## 17. Funcțiile șablon

Funcțiile șablon sunt o metodă de implementare a polimorfismului de compilare. Cu un șablon este posibil să creăm funcții generice și clase generice. O funcție generică definește un set general de operații care vor fi aplicate unor tipuri de date variate. Unei astfel de funcții, tipul de date asupra căruia va opera îi este transmis ca parametru. O astfel de funcție este creată cu ajutorul cuvântului cheie `template`.

**Forma generală:**
```cpp
template <class Tip>
tip_returnat nume_functie(lista_parametri) {
    // corpul functiei
}
```

**Trei situații în care un apel de funcție nu generează o versiune a funcției dintr-un șablon:**
1. Când funcția șablon are în lista de parametri doi parametri de tipul șablonului, iar noi apelăm funcția pentru două tipuri de date diferite.
2. Când funcția șablon are în lista de parametri un parametru de tipul șablonului și când mai avem o funcție definită cu același nume și un tip specificat, atunci se va executa funcția cu tipul deja specificat.
3. Când funcția șablon are în lista de parametri doi parametri de tipul șablonului, iar noi apelăm funcția pentru un tip și un pointer la acel tip.

---

## 18. Polimorfismul de compilare vs cel de execuție

Polimorfismul este o caracteristică a programării orientate pe obiecte care se referă la comportamentul metodelor (posibilitatea ca o funcție să se comporte diferit în contexte diferite).

Există două tipuri de polimorfism:
- **De compilare** (care se decide la compilare): cuprinde supraîncărcarea funcțiilor/operatorilor, șabloane și parametri cu valori implicite.
- **De execuție** (care se decide la execuție în funcție de anumite informații disponibile la momentul execuției): cuprinde instanțierea dinamică, moștenire și metode virtuale.

---

## 19. Funcții care returnează valoare vs referință

**Întoarcerea rezultatului prin valoare** reprezintă copierea valorii furnizate de funcția apelată pentru o instrucțiune `return` într-o variabilă temporară, de tipul funcției, creată în funcția apelantă.

**Întoarcerea rezultatului prin referință** reprezintă crearea unei referințe temporare de tipul funcției în funcția apelantă, către variabila întoarsă ca rezultat de funcția apelată.

---

## 20. Funcții de conversie între tipuri (clase)

Avem situația următoare: `B` — tip de date deja existent (clasă sau tip predefinit) și definim o clasă nouă `A`.

- **B → A:** se definește un constructor în clasa A cu un singur parametru de tip B: `A(B)`.
- **A → B:** supraîncărcăm operatorul "cast" al tipului B în clasa A: `(B)A`.

**Sintaxa pentru A → B:**
```cpp
class A {
public:
    operator B();
};
```

**Observație:** Constructorii cu un parametru sunt tratați ca metode de conversie implicită, chiar dacă nu pentru asta au fost creați. **Soluție:** se pune în fața constructorului cuvântul `explicit`.

---

## 21. Clasa generică (template) vs clasa abstractă

**Clasa generică** este o clasă care definește toți algoritmii definiți de ea, dar tipul de date care este manevrat efectiv va fi specificat ca un parametru la crearea obiectului acelei clase.

**Forma generală:**
```cpp
template <class Tip>
class numeclasa { /* ... */ };
```

Crearea unui exemplar:
```cpp
nume-clasa<tip> ob;
```

**Clasa abstractă** este o clasă în care avem cel puțin o metodă virtuală pură.

**Diferențe:**
- Clasa generică reprezintă o metodă a polimorfismului de **compilare**.
- Clasa abstractă reprezintă o metodă a polimorfismului de **execuție**.

**Sintaxa clasa abstractă:**
```cpp
class A { virtual f() = 0; };
```

O clasă abstractă constituie un tip incomplet care este folosit ca fundament pentru clasele derivate. Clasele generice sunt folositoare când o clasă conține caracteristici generale.

---

## 22. Transferul prin valoare vs transferul prin referință

**Transferul prin valoare** reprezintă copierea valorii transmise ca parametru actual în parametru formal, care este creat pe stivă la lansarea în execuție a funcției, ca o variabilă locală (automatică).

**Transferul prin referință** reprezintă crearea unei referințe locale către variabila transmisă ca parametru actual la lansarea în execuție a funcției.

---

## 23. Incluziunea de clase vs moștenirea de clase

**Moștenirea** este mecanismul prin care o clasă nouă este creată prin preluarea tuturor elementelor unei clase existente și adăugarea unor elemente noi specifice. Clasa de la care se pleacă se numește **clasă de bază**, iar clasa la care se ajunge se numește **clasă derivată**.

La derivare putem asocia clasei de bază un atribut de acces:
- **public** — elementele din clasa de bază își păstrează atributele de acces în clasa derivată
- **private** — elementele din clasa de bază devin private în clasa derivată
- **protected** — elementele publice din clasa de bază devin protected în clasa derivată

**Incluziunea de clase** se manifestă atunci când într-o clasă avem câmpuri de date de tipul altor clase.

**Observație:** Incluziunea → verbul "a avea"; Moștenirea → verbul "a fi".

### Moștenirea (IS A)
O clasă D **MOȘTENEȘTE** o clasă B, dacă se poate spune *"D ESTE (IS A) un obiect de tip B"*.

> Persoană ===> Student / Profesor / ... (Studentul ESTE o persoană).

**Sintaxa:**
```cpp
class A { /* ... */ };
class B : public A { /* ... */ };
```

### Incluziunea / Compunerea (HAS A)
O clasă D **APARȚINE** (compunere) de o clasă B, dacă se poate spune *"B ARE (HAS A) un obiect de tip D"*.

> Facultate ===> Student / Profesor / ... (Facultatea ARE studenți).

**Sintaxa:**
```cpp
class A { /* ... */ };
class B { A o1; int x; };
```

---

## 24. Constructorul de copiere

Constructorul de copiere este o funcție membră care ajută la inițializarea unui obiect utilizând alt obiect din aceeași clasă. Este un constructor cu un singur parametru de tipul clasei. El are o formă implicită care copiază octet cu octet.

**Sintaxa:**
```cpp
class_name(const class_name &ob);
```

**Utilizarea constructorului de copiere:**

- Pentru inițializarea obiectelor din alte obiecte de același tip:
  ```cpp
  class A {};
  A a, b(a);
  ```

- La transferul parametrilor unei funcții prin valoare:
  ```cpp
  class A {
      F(A ob);
  };
  ```

- La întoarcerea rezultatului unei funcții prin valoare:
  ```cpp
  class A {
      A F() {
          A ob;
          return ob;
      }
  };
  ```

---

## 25. Variabila constantă ca parametru al unei funcții

O variabilă constantă poate fi transmisă ca parametru al unei funcții doar când tipul parametrului funcției **nu** este de tip referință neconstantă și **nu** este de tip neconstant, deoarece:
- În primul caz: convertirea unei variabile constante la o referință neconstantă (eroare).
- În al doilea caz: se apelează constructorul de copiere care este de tipul `A(A &a)`, deci din nou va fi aceeași eroare.

---

## 26. Funcția prietenă (friend) a unei clase

Este posibil să permitem unei funcții care nu este membru să aibă acces la membri particulari ai unei clase folosind un `friend` (o funcție prietenă). O funcție friend are acces la membrii private și protected ai clasei căreia îi este prietenă. Pentru a declara o funcție friend includem prototipul ei în acea clasă precedat de cuvântul cheie `friend`.

**Exemplu:** supraîncărcarea operatorului `>>` pentru citire, respectiv `<<` pentru afișare.

```cpp
friend std::ostream& operator<<(std::ostream& os, const clasa& p);
```

---

## 27. Reguli ce verifică supraîncărcarea operatorilor

- Nu putem defini operatori noi. Doar supraîncărcăm operatori deja existenți.
- Nu putem modifica numărul operanzilor unui operator existent și nici sintaxa lor.
- Nu putem modifica prioritatea și nici asociativitatea operatorilor existenți.
- Există operatori care nu se pot supraîncărca (exemplu: `.`, `::`, `?:`, `.*`).
- Operatorii pot fi supraîncărcați ca metode sau ca funcții independente. Nu toți operatorii care pot fi supraîncărcați ca metode pot fi supraîncărcați ca funcții independente! (exemplu: `=`, `()`, `[]`, `->`).

---

## 28. Metode de proiectare prin care elementele unei clase se pot regăsi în dublu exemplar

1. **Moștenire multiplă, nevirtuală** — când moștenești o clasă și încă una care e derivată din prima clasă moștenită.
2. **Prin compunere** — poți să ai două obiecte din două clase diferite care moștenesc aceeași clasă de bază.
3. **Moștenire și compunere** (a aceleiași clase de bază).

---

## 29. Trei metode de implementare a polimorfismului de compilare

- Supraîncărcare funcții și operatori
- Șabloane (template-uri)
- Parametri cu valori implicite

---

## 30. Comportamentul operatorului `dynamic_cast`

Operatorul `dynamic_cast<>` se poate aplica pe pointeri sau referință, realizează convertirea unui obiect de un anumit tip la alt tip.

**Sintaxa:**
```cpp
dynamic_cast<tipul_la_care_vrem_sa_convertim>(ceea_ce_vrem_sa_convertim)
```

---

## 31. Tipuri de moștenire

### a. Moștenire private
Această moștenire presupune că totul din clasa de BAZĂ devine **private** în clasa DERIVATĂ. Singurele excepții sunt datele și metodele private care devin inaccesibile.

Acest tip de moștenire este cel implicit când nu specificăm niciun modificator după simbolul `:`.

### b. Moștenire protected
Tot ce nu e private în clasa de bază devine **protected** în clasa derivată.

### c. Moștenire publică
Aceasta este cea mai des folosită moștenire. Totul rămâne la fel ca în clasa de bază. Datele și metodele private tot inaccesibile rămân.

### Accesul asupra membrilor moșteniți

| Component declarat ca: | Clasa moștenită ca: | Acces în subclasă: |
|:----------------------:|:-------------------:|:------------------:|
| public                 | public              | public             |
| protected              | public              | protected          |
| private                | public              | none               |
| public                 | protected           | protected          |
| protected              | protected           | protected          |
| private                | protected           | none               |
| public                 | private             | private            |
| protected              | private             | private            |
| private                | private             | none               |

---

## 32. Pointeri constanți vs pointeri către constante

### POINTER CĂTRE OBIECT CONSTANT
Valoarea obiectului nu poate fi modificată, dar putem modifica obiectul către care arată pointerul.

**Sintaxa:** `const tip_de_date *p`

**Exemplu:**
```cpp
const int* p;     // pointer catre un intreg constant
                  // pointerul se poate muta, dar valoarea NU se poate schimba
int x = 3;
p = &x;           // ok
*p = 5;           // not ok
```

### POINTER CONSTANT CĂTRE OBIECT
Pointerul nu poate fi modificat, dar valoarea către care pointează da.

**Sintaxa:** `tip_de_date *const p`

**Exemplu:**
```cpp
int* const p;     // pointer constant catre un intreg
                  // pointerul NU se poate muta, dar valoarea se poate schimba
int x = 3;
p = &x;           // not ok
*p = 5;           // ok
```

---

## 33. Caracteristicile unei variabile statice a unei clase

**Proprietăți:**
- Variabilele statice sunt precedate de cuvântul-cheie `static`.
- O singură copie din acea variabilă va exista pentru toată clasa.
- O variabilă statică declarată în clasă nu este definită (nu are zonă de memorie alocată). Pentru a putea fi definite, sunt redeclarate în exteriorul clasei respective, folosind operatorul de rezoluție.
- Dat fiind că variabilele statice sunt instanțiate indiferent dacă sunt declarate sau nu obiecte, putem accesa variabilele statice fără a ne folosi de vreun obiect, prin intermediul operatorului de rezoluție.

**Exemplu:**
```cpp
class A {
    static int x;
};
int A::x = 5;
```

**Exemplu de utilizare:** pentru a reține numărul de instanțe ale unui obiect (și a limita instanțierea mai multor obiecte — ex: Singleton).

---

## 34. Mecanisme prin care se obține polimorfismul de funcții

Dintre: funcțiile friend, funcțiile inline, constructorii, funcțiile virtuale, destructorii.

**Răspuns:** funcții inline, constructori, funcții virtuale.

**Obs.:** nu poate exista decât un singur destructor pentru fiecare clasă.

---

## 35. Funcții care returnează valoare vs referință

**ÎNTOARCERE PRIN VALOARE** — copierea valorii furnizate de funcție într-o variabilă temporară, de tipul funcției.

**ÎNTOARCERE PRIN REFERINȚĂ** — crearea unei referințe temporare de tipul funcției în funcția apelantă, către variabila întoarsă ca rezultat de funcția apelată.

---

## 36. Funcții de conversie între tipuri (clase)

**Conversiile de tip se pot realiza prin:**

- **Supraîncărcarea operatorului unar "cast"** (se poate face conversia dintr-un tip clasă într-un tip fundamental sau într-un alt tip clasă).
  ```cpp
  operator TipData();
  ```

- **Prin intermediul constructorilor** (constă în definirea unui constructor care primește ca parametru tipul la care se face conversia). Constructorul întoarce întotdeauna un rezultat de tipul clasei de care aparține, prin urmare prin intermediul constructorilor se poate face conversia doar de la un tip fundamental sau un tip clasă la un alt tip clasă.

**OBS:** În cazul conversiei de la un tip clasă la alt tip clasă, constructorul trebuie să aibă acces la câmpurile private ale tipului clasă în care se dorește a se face conversia și prin urmare trebuie declarat ca funcție friend.

**Exemplu:** Fie clasa B (tip de date predefinit sau clasă) și se dorește a se face conversia la tipul A:
1. Supraîncărcăm operatorul de cast al tipului în clasa B:
   ```cpp
   class B { public: operator A(); };
   ```
2. Supraîncărcarea constructorului de copiere cu un singur parametru de tip B:
   ```cpp
   A(B);
   ```

**OBS:** Constructorii cu un parametru sunt tratați ca metode de conversie implicită, chiar dacă nu pentru asta au fost creați. **Soluție:** se pune în fața constructorului cuvântul `explicit`.

---

## 37. Polimorfismul de execuție folosind metode virtuale

Moștenirea virtuală este o metodă de implementare a polimorfismului de execuție.

Moștenirea virtuală este necesară când avem 2 clase derivate din clasa de bază și o a treia care moștenește cele 2 clase (apare **problema diamantului** — anumite elemente sunt moștenite de două ori, ceea ce conduce la ambiguitate).

---

## 38. Cele două feluri de folosire a cuvântului "virtual" la moștenire

### A) Moștenire virtuală
Se realizează folosind cuvântul cheie `virtual`.

**Exemplu:**
```cpp
class D : virtual public A
```

**Utilitate:** pentru a rezolva ambiguitatea diamantului (două clase derivă din clasa de bază și avem o a treia clasă care derivă din cele două clase).

### B) Funcții virtuale
Când definim funcțiile utilizând cuvântul cheie `virtual`, pentru a le putea redefini în clasa derivată.

**Exemplu:**
```cpp
class A {
    int x;
public:
    virtual int sum() { /* definitie functie */ };
    // functie initiala
};

class B : public A {
    int y;
public:
    virtual int sum() { /* redefinire functie */ };
};
```

---

## 39. Supraîncărcarea operatorului `[]`

Operatorul `[]`, alături de operatorul `()` și operatorul `=`, **NU** se pot supraîncărca folosind funcție friend. Aceștia trebuie supraîncărcați ca funcții membre.

- Este considerat operator binar.
- Operatorul `[]` poate fi folosit și la stânga unei atribuiri (obiectul întors este referință).

**Exemplu:**
```cpp
int v[100];
int& operator[](int i) { return vector[i]; }
```

---

## 40. Lista de inițializare a unui constructor

- Apare în implementarea constructorului, între antetul și corpul acestuia.
- Lista conține operatorul `:` urmat de numele fiecărui membru și valoarea acestuia, în ordinea în care membrii apar în definiția clasei.

**Utilizare:**
- Inițializarea variabilelor statice
- Inițializarea referințelor
- Inițializarea câmpurilor pentru care nu există un constructor implicit
- Inițializarea membrilor clasei de bază
- Din motive de eficiență

**Exemplu:**
```cpp
class A {
    int x, y;
public:
    A(int x, int y) : A(7, 9) {};
};
```

---

## 41. Polimorfism la compilare

Polimorfismul este o caracteristică a programării orientate pe obiecte care se referă la comportamentul metodelor (posibilitatea ca o funcție să se comporte diferit în contexte diferite).

**Polimorfismul de compilare** (care se decide la compilare) cuprinde:
- Supraîncărcarea funcțiilor/operatorilor
- Șabloane
- Parametri cu valori implicite

---

## 42. Polimorfism la execuție

**Polimorfismul de execuție** (care se decide la execuție în funcție de anumite informații disponibile la momentul execuției) cuprinde:
- Instanțiere dinamică
- Moștenire
- Metode virtuale

---

## 43. Comportamentul funcțiilor virtuale în constructori și în destructori

Dacă vrem să eliminăm porțiuni alocate dinamic și pentru clasa derivată, dar facem upcasting, trebuie să folosim **destructori virtuali**.

```cpp
class AbstractBase {
public:
    virtual ~AbstractBase() = 0;
};

class Derived : public AbstractBase {};

int main() {
    Derived d;
}
```
