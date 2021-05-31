import React from 'react';
import Training from'./Training/Training';
import {
    mdiRun,
    mdiYoga,
    mdiPlus,
    mdiHome,
    mdiBell,
    mdiFood,
    mdiTicket,
    mdiAccount,
    mdiArmFlex,
    mdiDumbbell,
    mdiChartLine,
    mdiChevronRight
  } from '@mdi/js';
  import {
    H4,
    // H5,
    // H6,
    Card,
    // Body2,
    // Caption,
    // Subtitle2,
    IconButton,
    // withResize,
    ToggleButton,
    // ProgressCircular,
  } from 'ui-neumorphism'
import Icon from '@mdi/react';

class Program extends React.Component {
    render() {
        return (
            <Card width={300} height={600}>
                <H4 style={{ fontWeight: '500', marginTop: '8px' }}>Program</H4>
                <Training/>
                <div className='fitness-app-nav-bar'>
                <ToggleButton selected dark={false} color='var(--primary)'>
                    <Icon path={mdiHome} size={1}></Icon>
                </ToggleButton>
                <ToggleButton  dark={false}>
                    <Icon path={mdiChartLine} size={1}></Icon>
                </ToggleButton>
                <ToggleButton  dark={false}>
                    <Icon path={mdiFood} size={1}></Icon>
                </ToggleButton>
                <ToggleButton dark={false}>
                    <Icon path={mdiBell} size={1}></Icon>
                </ToggleButton>
                <ToggleButton dark={false}>
                    <Icon path={mdiAccount} size={1}></Icon>
                </ToggleButton>
                </div>
            </Card>
        )
    }
}

export default Program;
