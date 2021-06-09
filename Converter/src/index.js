import _ from 'lodash';
import createMainSelectButtonsOptions from './domFunctions/MainSelectOptionsCreater'
import createLeftSelectOptions from './domFunctions/SelectOptionsForMeasurements'
import getResult from './domFunctions/ResultWriter'
import leftSelectButtonsClickListenner from './domFunctions/SelectButtonsListenners/LeftSelectButtonClickListenner'
import rightSelectButtonsClickListenner from './domFunctions/SelectButtonsListenners/RightSelectButtonClickListenner'
import mainSelectButtonsClickListenner from './domFunctions/SelectButtonsListenners/MainSelectButtonsClickListenner'


createMainSelectButtonsOptions();
createLeftSelectOptions();
getResult();
leftSelectButtonsClickListenner();
rightSelectButtonsClickListenner();
mainSelectButtonsClickListenner();
