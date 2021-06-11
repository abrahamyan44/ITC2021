import React from 'react';
import './Group.css';
import Icon from '@mdi/react'
import {
  Card,
  Caption,
  Subtitle2,
  ProgressCircular,
} from 'ui-neumorphism'

class Group extends React.Component {
    render() {
        const {dark, icon, title, content, procent} = this.props;
        return(
        <Card rounded={false} elevation={3} dark = {dark} className='group'>
            <Card flat className='nested-card'>
                <Icon path={icon} size={1.3} color='var(--primary)'/>
                <Card flat className='text-card'>
                    <Subtitle2 className='group-title'>
                        {title}
                    </Subtitle2>
                    <Caption secondary component='span'>
                        {content}
                    </Caption>
                </Card>
            </Card>
            <ProgressCircular value={procent} dark = {dark} color='var(--primary)'>
                {procent}%
            </ProgressCircular>
        </Card>
        )
    }
}

export default Group;