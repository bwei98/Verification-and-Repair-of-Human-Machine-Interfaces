# Verification-and-Repair-of-Human-Machine-Interfaces

## Abstract
Poorly designed interfaces can pose a major danger to users in systems where safety is a primary concern — for example, many inadequately created medical devices, which have rectifiable designs, have led to unnecessary fatalities.  This research project is focused on modeling these complex systems and the human interactions with them as finite state machines and to then prove or correct their safety.  There are three main thrusts to this project.  First, we model and simplify complex systems and possible human interactions with them into finite state processes.  Second, we create a way to systematically induce errors into our correct models based on typical erroneous human behavior.  Finally, we seek to procedurally correct potentially unsafe models.

## LTSA
The labelled transistion system analyser is a tool to create and analyse safety properties of finite state machines [documented here](https://www.doc.ic.ac.uk/~jnm/book/firstbook/ltsa-v2/index.html).  Models contains several sample models created to better understand this system and language -- these are models of an infusion pump, one correct and the others with minor errors based on the patterns.

## Implementation
This contains a preliminary implementation of a DFA in C++.  This will be used to eventaully create the mutation tool and the repair tool for analysing and repairing models.  Currently, this only includes basic DFA functions and a very limited and simple mutator.

## MoM 2019 Poster
Source files for the poster created for Meeting of the Minds 2019.

## Papers
Relevant Papers on the subject
