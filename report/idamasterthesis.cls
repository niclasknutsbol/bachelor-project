\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{idamasterthesis}
              [2011/04/19
               LaTeX idamasterthesis class]


\DeclareOption*{\PassOptionsToClass{\CurrentOption}{idathesis}}

\ProcessOptions

\LoadClass{idathesis}


\isbn{-}

\newcommand{\issn}{-}

\renewcommand{\idathesistype}{master}
\renewcommand{\ismaster}[1]{#1}

\newcommand{\makefront}{
  \renewcommand{\plainheadrulewidth}{0pt}
  \setcounter{page}{-1}       %% Front page starts at page -1
   \enlargethispage{8mm}
   \begin{center}
   \vspace*{-10mm}
   \center
    \faculty{%
      { \LARGE\textbf{Institutionen för datavetenskap}\\
        \large Department of Computer and Information Science\\[10mm]
        \swedishenglish{Examensarbete}{Final thesis}}\\[10mm]
    }
    {%
      {\footnotesize \swedishenglish{Filosofiska fakulteten FiF-avhandling}{Faculty of Arts and Science FiF-thesis} \@thesisnumber}\\[8mm]
    }
    {\begin{minipage}[c][20mm]{320pt}\center
      \LARGE\textbf{\swedishenglish{\@titleswedish}{\@titleenglish}}
    \end{minipage}}\\[8mm]
    \swedishenglish{av}{by}
    \\[10mm]
    {\Large\textbf{\@author}}\\[15mm]
    \large \@isrn\\[4mm]
    \@dateofpublication\\[15mm]
    \includegraphics[width=250pt,trim=100pt 100pt 100pt 50pt]{linkuniv_sv_framed}
   \end{center}
}


\renewcommand{\maketitle}{
  \renewcommand{\plainheadrulewidth}{0pt}
   \enlargethispage{8mm}
   \begin{center}
   \vspace*{-10mm}
   \center
    \faculty{%
      {\begin{minipage}[t]{360pt}
          \flushleft
          Linköpings universitet\\Institutionen för datavetenskap
        \end{minipage}\\[20mm]
        \Large \swedishenglish{Examensarbete}{Final thesis}}\\[15mm]}
    {%
      {\footnotesize \swedishenglish{Filosofiska fakulteten FiF-avhandling}{Faculty of Arts and Science FiF-thesis} \@thesisnumber}\\[8mm]
    }
    {\begin{minipage}[c][20mm]{320pt}\center
      \LARGE\textbf{\swedishenglish{\@titleswedish}{\@titleenglish}}
    \end{minipage}}\\[8mm]
    \swedishenglish{av}{by}
    \\[10mm]
    {\Large\textbf{\@author}}\\[15mm]
    \large \@isrn\\[4mm]
    \@dateofpublication
   \end{center}
   \vfill
   {\setlength{\parindent}{0mm}
   \makebox[20mm][l]{\swedishenglish{Handledare}{Supervisor}:}
    \begin{minipage}[t]{70mm}
      \@supervisor
    \end{minipage}\\[3mm]
    \makebox[20mm][l]{\swedishenglish{Examinator}{Examiner}:}
    \begin{minipage}[t]{70mm}
      \@examiner
    \end{minipage}} \\ \vspace*{4mm}

}


\newcommand{\maketitleold}{
  \pagenumbering{roman}
  \pagestyle{empty}
  \setcounter{page}{-1}       %% Front page starts at page -1

  %% Front page. Should not be edited.
  \hfil\hspace*{-4mm}
  \begin{minipage}{100mm}
    \center
    \textbf{\swedishenglish{Examensarbete}{Final thesis}} \\
    {\vbox to 28mm{\vfil\Large\textbf\makeatother\swedishenglish{\@titleswedish}{\@titleenglish}\makeatletter}}
    \vspace*{5mm}
    %Performed for \textbf{COMPANY A}\\
    %in cooperation with \textbf{COMPANY C} \\
    \vspace*{2mm}
    \swedishenglish{av}{by} \\
    \textbf{\@author} \\ \vspace*{4mm}
    LITH-IDA-EX-{}-\@publicationyear/\@thesisnumber-{}-SE \\ \vspace*{4mm}
    \@dateofpublication

  \end{minipage}
  
  \clearpage

%  \lhead[Linköpings universitet\\
%         Institutionen för datavetenskap]{}
  \renewcommand{\plainheadrulewidth}{0pt}
  \pagestyle{empty}

%% Title page. This page can be edited.
  \hfil\hspace*{-4mm}
  
  \begin{minipage}{110mm}
    \center
    \textbf{\swedishenglish{Examensarbete}{Final thesis}} \\
    {\vbox to 18mm{\vfil\Large\textbf\makeatother\swedishenglish{\@titleswedish}{\@titleenglish}\makeatletter}}
    \vspace*{3mm}
    \vspace*{2mm}
    \swedishenglish{av}{by} 
    \vspace*{2mm}
    \textbf{\@author} \\ \vspace*{4mm}
    LITH-IDA-EX-{}-\@publicationyear/\@thesisnumber-{}-SE
    \vspace*{70mm}
    \flushleft
    \swedishenglish{Handledare}{Supervisor}:
    \begin{minipage}[t]{70mm}
      \@supervisor
    \end{minipage} \\ \vspace*{4mm}
    \swedishenglish{Examinator}{Examiner}:\hspace*{5.5pt}
    \begin{minipage}[t]{70mm}
      \@examiner
    \end{minipage} \\ \vspace*{4mm}
    
  \end{minipage}\hfil
  \newpage
%  \lhead[]{}
  \pagestyle{empty}
  \phantom{Empty page}
  \newpage
  \normalsize
}


\newcommand{\makeintropages}{

%  \newcommand{\abstractparii}{\csname par\endcsname}
  %% pdfgraphics defines the standard file extension for includegraphics
  %%\pdfgraphics
  \changetext{}{}{}{5mm}{}
%  \changepage{40mm}{14mm}{-7mm}{-7mm}{0mm}{-25mm}{}{}{}
  \pagestyle{empty}
  \pagenumbering{roman}
  \makefront
  \thispagestyle{empty}
  \cleardoublepage
  \maketitle
  \thispagestyle{empty}
  \cleardoublepage
  \changetext{}{}{}{-5mm}{}
%  \thispagestyle{empty}
   \chapter*{\swedishenglish{Sammanfattning}{Abstract}}
   \@abstract
%  \abstractpage
  \cleardoublepage
%  \changepage{-40mm}{-14mm}{7mm}{7mm}{0mm}{25mm}{}{}{}
  \thispagestyle{empty}
  \cleardoublepage
%  \input{acknowledgement.tex}
%  \cleardoublepage

  \pagestyle{fancy}
  \thispagestyle{fancy}
  \tableofcontents
  \cleardoublepage
  \pagenumbering{arabic}
}

\AtEndDocument{
  \cleardoublepage
  \thispagestyle{empty}
  \begin{flushright}
  \includegraphics[width=2cm]{linkUniv_sigill_sv}
  \end{flushright}
  \vspace*{-10mm}
  \normalsize
\subsection*{På svenska}

Detta dokument hålls tillgängligt på Internet -- eller dess framtida
ersättare -- under en längre tid från publiceringsdatum under
förutsättning att inga extra-ordinära omständigheter uppstår.

Tillgång till dokumentet innebär tillstånd för var och en att läsa,
ladda ner, skriva ut enstaka kopior för enskilt bruk och att använda
det oförändrat för ickekommersiell forskning och för undervisning.
Överföring av upphovs-rätten vid en senare tidpunkt kan inte upphäva
detta tillstånd. All annan användning av dokumentet kräver
upphovsmannens medgivande. För att garantera äktheten, säkerheten och
tillgängligheten finns det lösningar av teknisk och administrativ art.

Upphovsmannens ideella rätt innefattar rätt att bli nämnd som
upphovsman i den omfattning som god sed kräver vid användning av
dokumentet på ovan beskrivna sätt samt skydd mot att dokumentet ändras
eller presenteras i sådan form eller i sådant sammanhang som är
kränkande för upphovsmannens litterära eller konstnärliga anseende
eller egenart.

För ytterligare information om Linköping University Electronic Press
se förlagets hemsida http://www.ep.liu.se/



\subsection*{In English}

The publishers will keep this document online on the Internet -- or
its possible replacement -- for a considerable time from the date of
publication barring exceptional circumstances.

The online availability of the document implies a permanent permission
for anyone to read, to download, to print out single copies for your
own use and to use it unchanged for any non-commercial research and
educational purpose. Subsequent transfers of copyright cannot revoke
this permission. All other uses of the document are conditional on the
consent of the copyright owner. The publisher has taken technical and
administrative measures to assure authenticity, security and
accessibility.

According to intellectual property law the author has the right to be
mentioned when his/her work is accessed as described above and to be
protected against infringement.

For additional information about the Linköping University Electronic
Press and its procedures for publication and for assurance of document
integrity, please refer to its WWW home page:
http://www.ep.liu.se/\\[6mm]

\copyright \@author
  }

% \newcommand{\exhibitpagebeforeabstract}{%
% \changetext{}{}{}{5mm}{}
% \thispagestyle{empty}
% \setlength{\parindent}{0mm}
% \faculty{\centerline{\footnotesize Linköping Studies in Science and Technology}
% \vspace{2mm}
% \centerline{\footnotesize Thesis No. \@thesisnumber}}{
% \centerline{\footnotesize \swedishenglish{Filosofiska fakulteten FiF-avhandling}{Faculty of Arts and Science FiF-thesis} \@thesisnumber}
% }
% \vspace{3mm}
% {\centering\Large\textbf{\swedishenglish{\@titleswedish}{\@titleenglish}}\\[2mm]}
% \centerline{\swedishenglish{av}{by}}
% \vspace{2mm}
% \centerline{\large\textbf{\@author}}
% \vspace{5mm}
% \footnotesize
% \centerline{\textbf{Licentiatavhandling}}
% \vspace{3mm}
% som för avläggande av \@degreetype\ licentiatexamen vid Linköpings universitet
% kommer att offentligt presenteras i \@presentationplace, hus \@presentationhouse, 
% Linköpings universitet, \@presentationtime.\\[7mm]
% \setlength\parskip{8pt}\centerline{\textbf{\swedishenglish{Sammanfattning}{Abstract}}}
% \vspace{3mm}\\[-\baselineskip]
% }
% 
% \newcommand{\exhibitpageafterabstract}{%
% 
% \textit{\swedishenglish{Studien har finansierats av}{This work has been supported} \@supportedby.}
% \vfill
% \centerline{\swedishenglish{Institutionen för datavetenskap}{Department of Computer and Information Science}}
% \centerline{Linköpings universitet}
% \centerline{\swedishenglish{581\,83 Linköping}{SE-581\,83 Linköping, Sweden}}
% \vspace{7mm}
% \hspace*{\fill}ISBN \@isbn\hspace*{\fill}\hspace*{\fill}ISSN \issn\hspace*{\fill}
% }
% 

