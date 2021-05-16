#!/bin/bash
groups $FT_USER | tr ' ' , | xargs echo -n
